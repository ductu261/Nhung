/*******************************************************************************
 * Description  : Viết một chương trình sao chép đầu vào ra đầu ra, thay thế mỗi 
 * tab bằng \t, mỗi backspace bằng \b, và mỗi backslash bằng \\.
 ******************************************************************************/
#include <stdio.h>

#define CHAR_TAB       '\t'
#define CHAR_BACKSPACE '\b'
#define CHAR_BACKSLASH '\\'

int main(void)
{
    int current_char;

    // Duyệt qua từng ký tự và chuyển đổi các ký tự điều khiển
    while ((current_char = getchar()) != EOF)
    {
        switch (current_char)
        {
            case CHAR_TAB:
                printf("\\t");
                break;
                
            case CHAR_BACKSPACE:
                printf("\\b");
                break;
                
            case CHAR_BACKSLASH:
                printf("\\\\");
                break;
                
            default:
                putchar(current_char);
                break;
        }
    }

    return 0;
}