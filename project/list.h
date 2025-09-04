#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义账号双向循环链表节点结构体
typedef struct account_password
{
    char account[15];
    char password[15];
    struct account_password *prev;
    struct account_password *next;
} SAP;

// 定义学生信息双向循环链表节点结构体
typedef struct student_data
{
    char name[20];
    char sex;
    int height;
    float score;
    char status[20];
    struct student_data *prev;
    struct student_data *next;
} SSD;

// 账号相关函数声明
extern SAP *head_SAP(void);
extern SAP *node_SAP(void);
extern void insert_SAP(SAP *prev_note, SAP *node, SAP *next_note);
extern void insert_head_SAP(SAP *head, SAP *node);
extern SAP *register_student(SAP *head);
extern void login_teacher_SAP(void);
extern void login_student_SAP(SAP *head);
extern void release_SAP(SAP *head);

// 学生信息相关函数声明
extern SSD *head_SSD(void);
extern SSD *node_SSD(void);
extern void insert_SSD(SSD *prev_note, SSD *node, SSD *next_note);
extern void insert_head_SSD(SSD *head, SSD *node);
extern void insert_tail_SSD(SSD *head, SSD *node);
extern void insert_mid_SSD(SSD *head, SSD *node);
extern void fun_insert_SSD(SSD *head);
extern void delete_head_SSD(SSD *head);
extern void delete_tail_SSD(SSD *head);
extern void delete_mid_SSD(SSD *head);
extern void fun_delete_SSD(SSD *head);
extern void modify_name_SSD(SSD *head);
extern void modify_sex_SSD(SSD *head);
extern void modify_height_SSD(SSD *head);
extern void modify_score_SSD(SSD *head);
extern void modify_status_SSD(SSD *head);
extern void fun_modify_SSD(SSD *head);
extern SSD *search_name_SSD(SSD *head);
extern void search_sex_SSD(SSD *head);
extern void search_height_SSD(SSD *head);
extern void search_score_SSD(SSD *head);
extern void fun_search_SSD(SSD *head);
extern void display_allstudent(SSD *head);
extern void release_SSD(SSD *head);
extern void view_announcements(void);
extern void publish_announcement(void);

#endif