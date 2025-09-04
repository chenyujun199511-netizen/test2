# 项目名称 
户外电子广告屏

# 项目介绍
本项目是一个基于嵌入式开发板的小区信息播报系统，用
于在液晶屏上展示通知、天气、欢迎语等信息，并支持图
片轮播功能。

# 环境依赖
    ununtu16.04 、Linux环境、ARM6818开发板、交叉编译工具链

# 编译的方法
编译
make 
清除+编译+执行
make all

## 项目结构
项目1/
├── bin/                # 可执行文件目录
│   ├── font            # 字库程序
│   └── main            # 主程序
├── include/            # 头文件目录
│   ├── font.h          # 字库头文件
│   ├── insert.h        # 链表操作头文件
│   ├── jconfig.h       # JPEG操作头文件
│   ├── jerror.h
│   ├── jmorecfg.h
│   ├── jpeglib.h       
│   └── lcdjpg.h        # LCD操作头文件
├── lib/                # 库文件目录
│   ├── libfont.a       # 字库静态库
│   ├── libjpeg.a       # JPEG静态库
│   ├── libjpeg.la
│   ├── libjpeg.so      # JPEG动态库
│   ├── libjpeg.so.9
│   └── libjpeg.so.9.1.0
├── main/               # 主程序源码
│   └── main.c          # 主程序入口
├── src/                # 功能模块源码
│   ├── images/             # 图片资源目录
│   ├── lcdjpg.c            # LCD和JPEG操作实现
│   ├── open_dir.c          # 目录操作实现
│   ├── struct.c            # 数据结构实现
│   └── images
│       ├── 1.bmp
│       ├── 2.bmp
│       └── 3.bmp
│     
├── Makefile            # 编译配置文件
└── README.md           # 项目说明文档

6 directories, 25 files

#版本
V1.0.0版本

#作者     
顶针  

#时间
2025.05.26

#联系方式
QQ：2039881801

