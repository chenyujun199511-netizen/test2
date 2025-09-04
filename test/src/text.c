#include "../include/head.h"
#include "../include/font.h"
#include "../include/lcdjpg.h"

char *now_time()
{
    static char buf_time[80];

    time_t nowtime;
    struct tm *timeinfo;

    time(&nowtime); // ��ȡ��ǰʱ��
    timeinfo = localtime(&nowtime);
    strftime(buf_time, sizeof(buf_time), "%Y-%m-%d %H:%M:%S", timeinfo);

    return buf_time;
}

char *weather()
{
    static char txt[500] = {
        "����Ԥ��:\n\t����,�Ϸ�ǿ���������������ϵ���,�㶫�����б��ꡣ\nͬʱ����������ͽ����Ӱ��,�������Ͻ����ֽ���,������½�����20������,�����½����Ƚϴ�,��ע�Ᵽů��\n"};

    return txt;
}

//------------------------------------------------
// ������x,y - ��ʼ���ꣻtext - Ҫ��ʾ���ַ�����color - ��ɫ��size - �ֺţ�max_width - ���������
void Display_WrappedText(int x, int y, const char *text, int color, int size, int max_width)
{
    int current_x = x; // ��ǰ����λ�õ�x���꣨��̬�仯��
    int current_y = y; // ��ǰ����λ�õ�y���꣨����ʱ�仯��

    // �ַ���ȶ��壨�����ֺ����ţ�
    int char_width = 8 * size;     // Ӣ���ַ���ȣ�����������8���أ�
    int cn_char_width = 16 * size; // �����ַ���ȣ�������Ӣ�ĵ�3����

    char line_buffer[1000]; // ���ַ����������洢��ǰ�����ݣ�
    int line_pos = 0;       // ��������ǰλ������

    // ��ѭ��������ַ������ַ���
    while (*text)
    {
        // ���1���������з�\n
        if (*text == '\n')
        {
            line_buffer[line_pos] = '\0';                               // ��ֹ��ǰ���ַ���
            Display_characterX(x, current_y, line_buffer, color, size); // ��ʾ����
            current_y += 16 * size;                                     // y�������ƣ��и�=16����*�ֺţ�
            line_pos = 0;                                               // �����л���������
            text++;                                                     // �ƶ�����һ���ַ�
            continue;                                                   // ������������
        }

        // �ж��ַ����ͣ�GBK�����������ֽ����λ��1��
        int is_cn = (*text & 0x80) ? 1 : 0;
        int this_char_width = is_cn ? cn_char_width : char_width;

        // ���2����ǰ�п�ȼ�����������
        if (current_x + (line_pos + 1) * this_char_width > max_width)
        {
            line_buffer[line_pos] = '\0';                               // ��ֹ��ǰ��
            Display_characterX(x, current_y, line_buffer, color, size); // ��ʾ
            current_y += 16 * size;                                     // ���У�y�������ƣ�
            line_pos = 0;                                               // ���û���������
            current_x = x;                                              // x����ص�����
        }

        // �洢��ǰ�ַ���������
        line_buffer[line_pos++] = *text; // �洢�ַ����ƶ�����
        text++;                          // Դ�ַ���ָ�����

        // ��������ģ���Ҫ�ٴ�һ���ֽڣ�GBK����ռ2�ֽڣ�
        if (is_cn)
        {
            line_buffer[line_pos++] = *text; // �洢���ĵڶ��ֽ�
            text++;                          // �ٴ��ƶ�ָ��
        }
    }

    // �������һ��δ��ʾ������
    if (line_pos > 0)
    {
        line_buffer[line_pos] = '\0';                               // ����ַ���������
        Display_characterX(x, current_y, line_buffer, color, size); // ��ʾʣ������
    }
}
