#include "list.h"

// 初始化账号链表头节点
SAP *head_SAP(void)
{
    SAP *head = malloc(sizeof(SAP));

    if (!head)
    {
        perror("分配头节点内存失败！");
        return NULL;
    }

    strcpy(head->account, "");
    strcpy(head->password, "");

    head->prev = head;
    head->next = head;

    return head;
}

// 创建账号链表新节点
SAP *node_SAP(void)
{
    SAP *node = malloc(sizeof(SAP));

    if (!node)
    {
        perror("分配节点内存失败！");
        return NULL;
    }

    strcpy(node->account, "");
    strcpy(node->password, "");

    node->prev = NULL;
    node->next = NULL;

    return node;
}

// 通用插入账号节点
void insert_SAP(SAP *prev_note, SAP *node, SAP *next_note)
{
    node->prev = prev_note;
    node->next = next_note;
    next_note->prev = node;
    prev_note->next = node;
}

// 头插账号节点
void insert_head_SAP(SAP *head, SAP *node)
{
    insert_SAP(head, node, head->next);
}

// 注册学生账号
SAP *register_student(SAP *head)
{
    SAP *node = node_SAP();

    char account[15];
    char password[15];
    int n = 0;

    // 输入账号
    while (!n)
    {
        printf("请输入注册账号(6-10字符,输入quit返回):\n");
        scanf("%s", account);

        if (strcmp(account, "quit") == 0)
        {
            free(node);
            return NULL;
        }
        // 限制账号长度
        if (strlen(account) < 6 || strlen(account) > 10)
        {
            printf("账号长度必须为6-10字符!\n");
            continue;
        }

        SAP *p = head->next;
        while (p != head)
        {
            // 防止有相同账号
            if (strcmp(p->account, account) == 0)
            {
                printf("账号已存在，请重新输入！\n");
                break;
            }
            p = p->next;
        }

        if (p == head)
        {
            strcpy(node->account, account);
            n = 1;
        }
    }

    // 输入密码
    n = 0;
    while (!n)
    {
        printf("请输入密码(6-10字符,输入quit返回):\n");
        scanf("%s", password);

        if (strcmp(password, "quit") == 0)
        {
            free(node);
            return NULL;
        }
        if (strlen(password) < 6 || strlen(password) > 10)
        {
            printf("密码长度必须为6-10字符!\n");
        }
        else
        {
            strcpy(node->password, password);
            n = 1;
        }
    }

    insert_head_SAP(head, node);

    printf("注册成功！\n");
    return node;
}

// 教师登录
void login_teacher_SAP(void)
{
    char account[15];
    char password[15];

    int n = 1;
    while (n > 0)
    {
        printf("请输入教师账号:\n");
        scanf("%s", account);
        printf("请输入密码:\n");
        scanf("%s", password);

        if (strcmp(account, "adminer") == 0 && strcmp(password, "123456") == 0)
        {
            printf("教师登录成功！\n");
            return;
        }
        else
        {
            n--;
            printf("账号或密码错误！\n");
        }
    }
    printf("登录失败，尝试次数已用尽。\n");
}

// 学生登录
void login_student_SAP(SAP *head)
{
    int choice;
    while (1)
    {
        printf("请选择操作:\n");
        printf("1. 注册\n2. 登录\n3. 退出\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            register_student(head);
        }
        else if (choice == 2)
        {
            char account[15];
            char password[15];
            printf("请输入账号:\n");
            scanf("%s", account);
            printf("请输入密码:\n");
            scanf("%s", password);

            SAP *p = head->next;
            while (p != head)
            {
                if (strcmp(p->account, account) == 0 && strcmp(p->password, password) == 0)
                {
                    printf("学生登录成功！\n");
                    return;
                }
                p = p->next;
            }
            printf("账号或密码错误！\n");
        }
        else if (choice == 3)
        {
            printf("退出登录。\n");
            break;
        }
        else
        {
            printf("请输入有效序号！\n");
        }
    }
}

// 释放账号链表
void release_SAP(SAP *head)
{
    SAP *p = head->next;
    while (p != head)
    {
        SAP *tmp = p;
        p = p->next;
        free(tmp);
    }
    free(head);
    printf("账号列表释放成功！\n");
}