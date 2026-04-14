/*******************************************************************************
 * Description  : Viết một chương trình đếm số khoảng trắng, tab và ký tự xuống 
 * dòng.
 ******************************************************************************/
#include <stdio.h>

#define CHAR_BLANK   ' '
#define CHAR_TAB     '\t'
#define CHAR_NEWLINE '\n'

int main(void)
{
    int current_char;
    int blank_count   = 0;
    int tab_count     = 0;
    int newline_count = 0;

    // Lặp qua đầu vào chuẩn cho đến khi kết thúc file
    while ((current_char = getchar()) != EOF)
    {
        if (current_char == CHAR_BLANK)
        {
            blank_count++;
        }
        else if (current_char == CHAR_TAB)
        {
            tab_count++;
        }
        else if (current_char == CHAR_NEWLINE)
        {
            newline_count++;
        }
    }

    printf("Khoang trang: %d, Tab: %d, Xuong dong: %d\n", 
           blank_count, tab_count, newline_count);

    return 0;
}