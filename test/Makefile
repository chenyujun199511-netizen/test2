#变量定义部分：
TAR = bin/main               # 定义最终生成的可执行文件路径
SRC = $(wildcard src/*.c)    # 使用wildcard函数获取src目录下所有.c文件
MAIN = main/main.c           # 定义主程序文件路径
INC = -I ./include/          # 指定头文件包含路径
CC = arm-linux-gcc           # 指定交叉编译器

#库文件链接部分：
#静态库
#LIBA = -L ./lib/liba -libfont.a//错误写法，不要打文件名，直接打库名
LIBA = -L ./lib -lfont       # 链接静态库libfont.a，-l表示链接库，lib表示库名，font表示库名
#动态库
LIBSO = -L ./lib -ljpeg      # 链接动态库libjpeg.so

#伪指令
.PHONY:$(TAR) run clean


#目标:依赖
$(TAR): $(MAIN) $(SRC)       # 目标文件依赖主程序和所有源文件
	$(CC)  $^ -o $@ $(INC) $(LIBSO) $(LIBA)	# 编译命令
    # $^ 表示所有依赖文件
    # $@ 表示目标文件

#执行
run:
	./$(TAR)

#在clean前面加上.PHONY使之变成伪指令
#.PHONY:clean
#清除
clean:
	$(RM) $(TAR)

#make all的时候一次性执行三条指令
all:clean $(TAR) run
