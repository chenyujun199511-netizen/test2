#include "list.h"

// 初始化学生信息链表头节点
SSD *head_SSD(void)
{
    SSD *head = malloc(sizeof(SSD));

    if (!head)
    {
        perror("分配头节点内存失败！");
        return NULL;
    }

    strcpy(head->name, "");
    head->sex = ' ';
    head->height = 0;
    head->score = 0;
    strcpy(head->status, "");

    head->prev = head;
    head->next = head;

    return head;
}

// 创建学生信息链表新节点
SSD *node_SSD(void)
{
    SSD *node = malloc(sizeof(SSD));
    if (!node)
    {
        perror("分配节点内存失败！");
        return NULL;
    }
    strcpy(node->name, "");
    node->sex = ' ';
    node->height = 0;
    node->score = 0;
    strcpy(node->status, "在学");

    node->prev = NULL;
    node->next = NULL;

    return node;
}

// 通用插入学生节点
void insert_SSD(SSD *prev_note, SSD *node, SSD *next_note)
{
    node->prev = prev_note;
    node->next = next_note;
    next_note->prev = node;
    prev_note->next = node;
}

// 头插学生节点
void insert_head_SSD(SSD *head, SSD *node)
{
    insert_SSD(head, node, head->next);
}

// 尾插学生节点
void insert_tail_SSD(SSD *head, SSD *node)
{
    insert_SSD(head->prev, node, head);
}

// 中间插学生节点
void insert_mid_SSD(SSD *head, SSD *node)
{
    SSD *p = search_name_SSD(head);
    if (p != head)
    {
        insert_SSD(p, node, p->next);
    }
    else
    {
        printf("未找到指定位置，取消插入。\n");
        free(node);
    }
}

// 插入学生信息功能
void fun_insert_SSD(SSD *head)
{
    int choice;
    while (1)
    {
        SSD *node = node_SSD();
        printf("请输入学生信息：\n");
        printf("姓名：");
        scanf("%s", node->name);
        printf("性别(M/W):");
        scanf(" %c", &node->sex);
        printf("身高(cm):");
        scanf("%d", &node->height);
        printf("成绩：");
        scanf("%f", &node->score);

        printf("请选择插入方式(输入0返回):\n");
        printf("1. 头插\n2. 尾插\n3. 中间插\n");
        scanf("%d", &choice);

        if (choice == 0)
        {
            free(node);
            break;
        }
        else if (choice == 1)
        {
            insert_head_SSD(head, node);
        }
        else if (choice == 2)
        {
            insert_tail_SSD(head, node);
        }
        else if (choice == 3)
        {
            insert_mid_SSD(head, node);
        }
        else
        {
            printf("请输入有效序号！\n");
            free(node);
        }
    }
}

// 头删学生节点
void delete_head_SSD(SSD *head)
{
    if (head->next == head)
    {
        printf("链表为空，无法删除！\n");
        return;
    }
    
    SSD *tmp = head->next;
    head->next = tmp->next;
    tmp->next->prev = head;

    free(tmp);
    printf("头删成功！\n");
}

// 尾删学生节点
void delete_tail_SSD(SSD *head)
{
    if (head->prev == head)
    {
        printf("链表为空，无法删除！\n");
        return;
    }

    SSD *tmp = head->prev;
    head->prev = tmp->prev;
    tmp->prev->next = head;

    free(tmp);
    printf("尾删成功！\n");
}

// 中间删学生节点
void delete_mid_SSD(SSD *head)
{
    SSD *p = search_name_SSD(head);

    if (p == head)
    {
        printf("未找到学生，无法删除！\n");
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    printf("删除成功！\n");
}

// 删除学生信息功能
void fun_delete_SSD(SSD *head)
{
    int choice;
    while (1)
    {
        printf("请选择删除方式(输入0返回):\n");
        printf("1. 头删\n2. 尾删\n3. 中间删\n");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            delete_head_SSD(head);
        }
        else if (choice == 2)
        {
            delete_tail_SSD(head);
        }
        else if (choice == 3)
        {
            delete_mid_SSD(head);
        }
        else
        {
            printf("请输入有效序号！\n");
        }
    }
}

// 修改学生姓名
void modify_name_SSD(SSD *head)
{
    SSD *p = search_name_SSD(head);

    if (p == head)
        return;

    char name[20];

    printf("请输入新姓名：\n");
    scanf("%s", name);
    strncpy(p->name, name,strlen(name));
    printf("姓名修改成功！\n");
}

// 修改学生性别
void modify_sex_SSD(SSD *head)
{
    SSD *p = search_name_SSD(head);

    if (p == head)
        return;

    char sex;

    printf("请输入新性别(M/W):\n");
    scanf(" %c", &sex);
    p->sex = sex;
    printf("性别修改成功！\n");
}

// 修改学生身高
void modify_height_SSD(SSD *head)
{
    SSD *p = search_name_SSD(head);

    if (p == head)
        return;

    int height;

    printf("请输入新身高：\n");
    scanf("%d", &height);
    p->height = height;
    printf("身高修改成功！\n");
}

// 修改学生成绩
void modify_score_SSD(SSD *head)
{
    SSD *p = search_name_SSD(head);

    if (p == head)
        return;

    float score;

    printf("请输入新成绩：\n");
    scanf("%f", &score);
    p->score = score;
    printf("成绩修改成功！\n");
}

// 修改学生状态
void modify_status_SSD(SSD *head)
{
    SSD *p = search_name_SSD(head);

    if (p == head)
        return;

    int choice;

    printf("请选择新状态：\n");
    printf("1. 在学\n2. 休学\n3. 退学\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        strcpy(p->status, "在学");
    }
    else if (choice == 2)
    {
        strcpy(p->status, "休学");
    }
    else if (choice == 3)
    {
        strcpy(p->status, "退学");
    }
    else
    {
        printf("无效状态！\n");
        return;
    }
    printf("状态修改成功！\n");
}

// 修改学生信息功能
void fun_modify_SSD(SSD *head)
{
    int choice;
    while (1)
    {
        printf("请选择修改项目(输入0返回:\n");
        printf("1. 姓名\n2. 性别\n3. 身高\n4. 成绩\n5. 状态\n");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            modify_name_SSD(head);
        }
        else if (choice == 2)
        {
            modify_sex_SSD(head);
        }
        else if (choice == 3)
        {
            modify_height_SSD(head);
        }
        else if (choice == 4)
        {
            modify_score_SSD(head);
        }
        else if (choice == 5)
        {
            modify_status_SSD(head);
        }
        else
        {
            printf("请输入有效序号！\n");
        }
    }
}

// 按姓名查找学生
SSD *search_name_SSD(SSD *head)
{
    char name[20];

    printf("请输入要查找的姓名：\n");
    scanf("%s", name);

    SSD *p = head->next;

    while (p != head)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("找到学生：%s\n", p->name);
            return p;
        }

        p = p->next;
    }
    printf("未找到该学生！\n");

    return head;
}

// 按性别查找学生
void search_sex_SSD(SSD *head)
{
    char sex;
    printf("请输入要查找的性别(M/W)：\n");
    scanf(" %c", &sex);
    printf("%-17s%-15s%-15s%-15s%-18s\n", "name", "sex", "height", "score", "status");

    SSD *p = head->next;

    while (p != head)
    {
        if (p->sex == sex)
        {
            printf("%-20s%-15c%-15d%-15.2f%-15s\n", p->name, p->sex, p->height, p->score, p->status);
        }
        p = p->next;
    }
}

// 按身高查找学生
void search_height_SSD(SSD *head)
{
    int height;
    printf("请输入要查找的身高：\n");
    scanf("%d", &height);
    printf("%-17s%-15s%-15s%-15s%-18s\n", "name", "sex", "height", "score", "status");

    SSD *p = head->next;

    while (p != head)
    {
        if (p->height == height)
        {
            printf("%-20s%-15c%-15d%-15.2f%-15s\n", p->name, p->sex, p->height, p->score, p->status);
        }
        p = p->next;
    }
}

// 按成绩查找学生
void search_score_SSD(SSD *head)
{
    float score;
    printf("请输入要查找的成绩：\n");
    scanf("%f", &score);
    printf("%-17s%-15s%-15s%-15s%-18s\n", "name", "sex", "height", "score", "status");

    SSD *p = head->next;

    while (p != head)
    {
        if (p->score == score)
        {
            printf("%-20s%-15c%-15d%-15.2f%-15s\n", p->name, p->sex, p->height, p->score, p->status);
        }
        p = p->next;
    }
}

// 查找学生信息功能
void fun_search_SSD(SSD *head)
{
    int choice;
    while (1)
    {
        printf("请选择查找项目(输入0返回):\n");
        printf("1. 姓名\n2. 性别\n3. 身高\n4. 成绩\n");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            search_name_SSD(head);
        }
        else if (choice == 2)
        {
            search_sex_SSD(head);
        }
        else if (choice == 3)
        {
            search_height_SSD(head);
        }
        else if (choice == 4)
        {
            search_score_SSD(head);
        }
        else
        {
            printf("请输入有效序号！\n");
        }
    }
}

// 显示所有学生信息
void display_allstudent(SSD *head)
{
    printf("%-17s%-15s%-15s%-15s%-18s\n", "name", "sex", "height", "score", "status");

    SSD *p = head->next;

    while (p != head)
    {
        printf("%-20s%-15c%-15d%-15.2f%-15s\n", p->name, p->sex, p->height, p->score, p->status);
        p = p->next;
    }
}

// 释放学生信息链表
void release_SSD(SSD *head)
{
    SSD *p = head->next;
    
    while (p != head)
    {
        SSD *tmp = p;
        p = p->next;
        free(tmp);
    }
    free(head);
    printf("学生信息列表释放成功！\n");
}

// 查看公告
void view_announcements(void)
{
    FILE *file = fopen("announcements.txt", "r");
    if (!file)
    {
        printf("暂无公告！\n");
        return;
    }
    char line[256];
    printf("公告列表：\n");
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
}

// 发布公告
void publish_announcement(void)
{
    FILE *file = fopen("announcements.txt", "a");
    if (!file)
    {
        printf("无法发布公告！\n");
        return;
    }
    char announcement[256];
    printf("请输入公告内容：\n");
    getchar(); // 清除输入缓冲区
    fgets(announcement, sizeof(announcement), stdin);
    fprintf(file, "%s", announcement);
    fclose(file);
    printf("公告发布成功！\n");
}