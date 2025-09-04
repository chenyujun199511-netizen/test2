#include "../include/head.h"
#include "../include/font.h"
#include "../include/lcdjpg.h"
// 功能:实现一张小于800*480的任意大小的bmp图片
int show_bmp_size(int *addr, char *bmp_path, int offset_x, int offset_y)
{
    // 打开bmp图(任意大小:长宽必须是4的倍数)
    int fd_bmp = open(bmp_path, O_RDWR);
    if (fd_bmp < 0)
    {
        printf("open bmp fail\n");
        return -1;
    }

    // 计算bmp图片的高度和高度
    int height = 0;
    int width = 0;
    lseek(fd_bmp, 18, SEEK_SET);
    read(fd_bmp, &width, 4);  // 读取bmp宽度
    read(fd_bmp, &height, 4); // 读取bmp高度

    // 读取bmp图
    lseek(fd_bmp, 54, SEEK_SET);
    char buf[width * height * 3]; // 变长数组不能初始化
    read(fd_bmp, buf, width * height * 3);

    // 读写lcd文件
    int x = 0; // 横轴
    int y = 0; // 纵轴
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            // bmp照片最后一行的起始点的坐标是(offset_x,offset_y+height-1)
            *(addr + ((offset_y + height - 1) - y) * 800 + offset_x + x) =
                buf[(y * width + x) * 3 + 0] |
                buf[(y * width + x) * 3 + 1] << 8 |
                buf[(y * width + x) * 3 + 2] << 16;
        }
    }

    // 关闭bmp
    close(fd_bmp);
}

// 打开目录并查找图片文件
void open_dir(char *path, SIM *head)
{
    // 打开目录
    DIR *dp = opendir("./images");
    if (dp == NULL)
    {
        printf("opendir fail\n");
        return;
    }

    struct dirent *ep = NULL; // 目录结构体，这是一个结构体类型，定义在 <dirent.h> 头文件中

    SIM *node = NULL; // 双向链表结构体节点
    while (1)
    {
        // 读目录(不停读取的时候指针会一直偏移,直到NULL为止)
        ep = readdir(dp);
        if (ep == NULL) // 目录读取结束
        {
            break;
        }

        if (ep->d_name[0] == '.')
            continue;

        // 获取目录里面的(有效的)文件名
        printf("ep->d_name = %s\n", ep->d_name);
        node = node_SIM(ep->d_name);
        insert_tail(head, node);
        printf("insert ok!\n");
    }
    // 关闭目录
    closedir(dp);
}
