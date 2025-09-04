#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

typedef struct image
{
    char image_name[20];
    struct image *prev;
    struct image *next;
} SIM;

// 万能插
extern void insert(SIM *prev_node, SIM *node, SIM *next_node);
// 头插学生节点
extern void insert_head(SIM *head, SIM *node);
// 尾插节点
extern void insert_tail(SIM *head, SIM *node);
// 初始化头结点
extern SIM *head_SIM();
// 创建图片链表新节点
extern SIM *node_SIM(char *name);
// 释放图片信息链表
extern void release_SIM(SIM *head);

// 参数：x,y - 起始坐标；text - 要显示的字符串；color - 颜色；size - 字号；max_width - 单行最大宽度
extern void Display_WrappedText(int x, int y, const char *text, int color, int size, int max_width);
// 获取当前时间
extern char *now_time();
// 获取当前天气
extern char *weather();

// 打开/src/images文件夹并将图片插入到链表中
extern void open_dir(char *path, SIM *head);
// 功能:实现一张800*480的bmp图片
extern int show_bmp(int *addr, char *bmp_path);
// 功能:实现一张小于800*480的bmp图片
extern int show_bmp_size(int *addr, char *bmp_path, int offset_x, int offset_y);

#endif