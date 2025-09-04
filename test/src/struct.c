#include "../include/head.h"

// 初始化图片链表头节点
SIM *head_SIM()
{
    SIM *head = malloc(sizeof(SIM));
    if (!head)
    {
        perror("分配头节点内存失败！");
        return NULL;
    }

    strcpy(head->image_name, "");
    head->prev = head;
    head->next = head;

    return head;
}

// 创建图片链表新节点
SIM *node_SIM(char *name)
{
    if (name == NULL)
    {
        printf("Error: NULL name in node_SIM()\n");
        return NULL;
    }

    SIM *node = malloc(sizeof(SIM));
    if (!node)
    {
        perror("分配节点内存失败！");
        return NULL;
    }

    strncpy(node->image_name, name, 19);
    node->prev = NULL;
    node->next = NULL;

    return node;
}

// 释放学生信息链表
void release_SIM(SIM *head)
{
    SIM *p = head->next;

    while (p != head)
    {
        SIM *tmp = p;
        p = p->next;
        free(tmp);
    }

    free(head);
    printf("链表释放成功！\n");
}

// 万能插
void insert(SIM *prev_node, SIM *node, SIM *next_node)
{
    node->prev = prev_node;
    node->next = next_node;
    next_node->prev = node;
    prev_node->next = node;
}

// 头插节点
void insert_head(SIM *head, SIM *node)
{
    if (head == NULL || node == NULL)
    {
        printf("Error: NULL pointer in insert_head()\n");
        return;
    }
    insert(head, node, head->next);
}

// 尾插节点
void insert_tail(SIM *head, SIM *node)
{
    if (head == NULL || node == NULL)
    {
        printf("Error: NULL pointer in insert_tail()\n");
        return;
    }
    insert(head->prev, node, head);
}