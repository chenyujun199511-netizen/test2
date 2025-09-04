#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "../include/lcdjpg.h"
#include "../include/head.h"
#include "../include/font.h"

int main()
{
	int RED = 0x00FF0000;
	int GREEN = 0x0000FF00;
	int BLACK = 0x00000000;

	SIM *head = head_SIM();
	if (head == NULL)
	{
		perror("head");
		return -1;
	}
	open_dir("/Even/1.project/images", head); // 打开图片目录

	int fd_lcd = open("/dev/fb0", O_RDWR);
	if (fd_lcd < 0)
	{
		perror("open lcd fail!");
		return -1;
	}

	// 映射
	int *addr = mmap(NULL,
					 800 * 480 * 4,
					 PROT_READ | PROT_WRITE,
					 MAP_SHARED,
					 fd_lcd,
					 0);
	if (addr == MAP_FAILED)
	{
		perror("mmap lcd");
		return -1;
	}

	Init_Font();
	while (1)
	{
		int i = 0;
		Clean_Area(0, 0, 800, 480, BLACK);
		// 显示时间、天气文本
		while (i < 5)
		{
			Display_WrappedText(10, 10, now_time(), GREEN, 3, 1300);
			Display_WrappedText(50, 100, weather(), RED, 3, 1300);
			sleep(1);
			Clean_Area(400, 0, 800, 100, BLACK);
			i += 1;
		}

		// 广告图
		SIM *p = NULL;
		for (p = head->next; p != head; p = p->next)
		{
			Display_WrappedText(10, 10, now_time(), GREEN, 3, 1300);
			// show_bmp(addr, p->image_name);
			show_bmp_size(addr, p->image_name, 0, 100);
			sleep(1);
			Clean_Area(400, 0, 800, 100, BLACK);
		}
	}
	UnInit_Font();

	munmap(addr, 800 * 480 * 4);
	close(fd_lcd);
	release_SIM(head);

	return 0;
}
