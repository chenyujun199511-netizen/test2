#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "list.h"

int main(int argc, char **argv)
{
    SetConsoleOutputCP(65001);

    // 初始化链表
    SSD *headSSD = head_SSD();
    SAP *headSAP = head_SAP();

    // 添加基本数据
    SSD *node1 = node_SSD();
    strcpy(node1->name, "蔡徐坤");
    node1->sex = 'M';
    node1->height = 180;
    node1->score = 99;
    strcpy(node1->status, "在学");
    insert_head_SSD(headSSD, node1);

    SSD *node2 = node_SSD();
    strcpy(node2->name, "马嘉祺");
    node2->sex = 'W';
    node2->height = 181;
    node2->score = 90;
    strcpy(node2->status, "在学");
    insert_head_SSD(headSSD, node2);

    SSD *node3 = node_SSD();
    strcpy(node3->name, "宋亚轩");
    node3->sex = 'M';
    node3->height = 170;
    node3->score = 89;
    strcpy(node3->status, "在学");
    insert_head_SSD(headSSD, node3);

    SSD *node4 = node_SSD();
    strcpy(node4->name, "严浩翔");
    node4->sex = 'W';
    node4->height = 160;
    node4->score = 98;
    strcpy(node4->status, "在学");
    insert_head_SSD(headSSD, node4);

    SSD *node5 = node_SSD();
    strcpy(node5->name, "贺峻霖");
    node5->sex = 'M';
    node5->height = 180;
    node5->score = 92;
    strcpy(node5->status, "在学");
    insert_head_SSD(headSSD, node5);

    // 主菜单
    int choice;
    printf("欢迎使用学生管理系统！\n");
    while (1)
    {
        printf("请选择登录身份(输入0退出):\n");
        printf("1. 教师\n2. 学生\n");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            login_teacher_SAP();
            while (1)
            {
                printf("请选择操作(输入0返回):\n");
                printf("1. 插入学生\n2. 删除学生\n3. 修改学生信息\n4. 查找学生\n5. 显示所有学生\n6. 发布公告\n");
                scanf("%d", &choice);
                if (choice == 0)
                {
                    break;
                }
                else if (choice == 1)
                {
                    fun_insert_SSD(headSSD);
                }
                else if (choice == 2)
                {
                    fun_delete_SSD(headSSD);
                }
                else if (choice == 3)
                {
                    fun_modify_SSD(headSSD); // 支持修改状态
                }
                else if (choice == 4)
                {
                    fun_search_SSD(headSSD);
                }
                else if (choice == 5)
                {
                    display_allstudent(headSSD);
                }
                else if (choice == 6)
                {
                    publish_announcement();
                }
                else
                {
                    printf("请输入有效序号！\n");
                }
            }
        }
        else if (choice == 2)
        {
            login_student_SAP(headSAP);
            while (1)
            {
                printf("请选择操作(输入0返回):\n");
                printf("1. 查看个人信息\n2. 查看公告\n");
                scanf("%d", &choice);

                if (choice == 0)
                {
                    break;
                }
                else if (choice == 1)
                {
                    SSD *student = search_name_SSD(headSSD);
                    if (student != headSSD)
                    {
                        printf("%-17s%-15s%-15s%-15s%-18s\n", "name", "sex", "height", "score", "status");
                        printf("%-20s%-15c%-15d%-15.2f%-15s\n", student->name, student->sex, student->height, student->score, student->status);
                    }
                }
                else if (choice == 2)
                {
                    view_announcements();
                }
                else
                {
                    printf("请输入有效序号！\n");
                }
            }
        }
        else
        {
            printf("请输入有效序号！\n");
        }
    }

    // 释放资源
    release_SSD(headSSD);
    release_SAP(headSAP);

    return 0;

}