#include "../include/head.h"
#include "../include/font.h"
#include "../include/lcdjpg.h"

char *now_time()
{
    static char buf_time[80];

    time_t nowtime;
    struct tm *timeinfo;

    time(&nowtime); // 获取当前时间
    timeinfo = localtime(&nowtime);
    strftime(buf_time, sizeof(buf_time), "%Y-%m-%d %H:%M:%S", timeinfo);

    return buf_time;
}

char *weather()
{
    static char txt[500] = {
        "天气预报:\n\t今日,南方强降雨区域移至华南地区,广东地区有暴雨。\n同时随着冷空气和降雨的影响,长江以南将出现降温,最高气温降将至20℃左右,气温下降幅度较大,请注意保暖。\n"};

    return txt;
}

//------------------------------------------------
// 参数：x,y - 起始坐标；text - 要显示的字符串；color - 颜色；size - 字号；max_width - 单行最大宽度
void Display_WrappedText(int x, int y, const char *text, int color, int size, int max_width)
{
    int current_x = x; // 当前绘制位置的x坐标（动态变化）
    int current_y = y; // 当前绘制位置的y坐标（换行时变化）

    // 字符宽度定义（根据字号缩放）
    int char_width = 8 * size;     // 英文字符宽度（假设基础宽度8像素）
    int cn_char_width = 16 * size; // 中文字符宽度（中文是英文的3倍宽）

    char line_buffer[1000]; // 行字符缓冲区（存储当前行内容）
    int line_pos = 0;       // 缓冲区当前位置索引

    // 主循环：逐个字符处理字符串
    while (*text)
    {
        // 情况1：遇到换行符\n
        if (*text == '\n')
        {
            line_buffer[line_pos] = '\0';                               // 终止当前行字符串
            Display_characterX(x, current_y, line_buffer, color, size); // 显示该行
            current_y += 16 * size;                                     // y坐标下移（行高=16像素*字号）
            line_pos = 0;                                               // 重置行缓冲区索引
            text++;                                                     // 移动到下一个字符
            continue;                                                   // 跳过后续处理
        }

        // 判断字符类型（GBK编码中文首字节最高位是1）
        int is_cn = (*text & 0x80) ? 1 : 0;
        int this_char_width = is_cn ? cn_char_width : char_width;

        // 情况2：当前行宽度即将超出限制
        if (current_x + (line_pos + 1) * this_char_width > max_width)
        {
            line_buffer[line_pos] = '\0';                               // 终止当前行
            Display_characterX(x, current_y, line_buffer, color, size); // 显示
            current_y += 16 * size;                                     // 换行（y坐标下移）
            line_pos = 0;                                               // 重置缓冲区索引
            current_x = x;                                              // x坐标回到行首
        }

        // 存储当前字符到缓冲区
        line_buffer[line_pos++] = *text; // 存储字符并移动索引
        text++;                          // 源字符串指针后移

        // 如果是中文，需要再存一个字节（GBK编码占2字节）
        if (is_cn)
        {
            line_buffer[line_pos++] = *text; // 存储中文第二字节
            text++;                          // 再次移动指针
        }
    }

    // 处理最后一行未显示的内容
    if (line_pos > 0)
    {
        line_buffer[line_pos] = '\0';                               // 添加字符串结束符
        Display_characterX(x, current_y, line_buffer, color, size); // 显示剩余内容
    }
}
