/*******************************************************************************
 * Description  : Viết một chương trình xóa các khoảng trắng và tab ở cuối mỗi 
 * dòng đầu vào, và xóa hoàn toàn các dòng trống.
 ******************************************************************************/
#include <stdio.h>

#define MAX_LINE_LENGTH 1024
#define CHAR_NEWLINE    '\n'
#define CHAR_BLANK      ' '
#define CHAR_TAB        '\t'
#define STRING_TERMINATOR '\0'

// Các nguyên mẫu hàm
int fetch_line(char *line_buffer, int max_length);
int trim_trailing(char *line_buffer, int current_length);

int main(void)
{
    char line_buffer[MAX_LINE_LENGTH];
    int current_length;

    // Đọc từng dòng, xử lý khoảng trắng thừa và in ra nếu dòng không rỗng
    while ((current_length = fetch_line(line_buffer, MAX_LINE_LENGTH)) > 0)
    {
        current_length = trim_trailing(line_buffer, current_length);
        
        if (current_length > 0)
        {
            printf("%s\n", line_buffer);
        }
    }

    return 0;
}

int fetch_line(char *line_buffer, int max_length)
{
    int current_char;
    int iterator = 0;

    // Đọc đến khi gặp ký tự xuống dòng hoặc hết sức chứa
    while ((iterator < max_length - 1) && 
           ((current_char = getchar()) != EOF) && 
           (current_char != CHAR_NEWLINE))
    {
        line_buffer[iterator] = (char)current_char;
        iterator++;
    }

    line_buffer[iterator] = STRING_TERMINATOR;
    return iterator;
}

int trim_trailing(char *line_buffer, int current_length)
{
    int index = current_length - 1;

    // Quét ngược từ cuối chuỗi để cắt bỏ khoảng trắng và tab
    while ((index >= 0) && 
           ((line_buffer[index] == CHAR_BLANK) || 
            (line_buffer[index] == CHAR_TAB)))
    {
        index--;
    }

    // Đặt lại ký tự kết thúc chuỗi sau khi đã cắt
    line_buffer[index + 1] = STRING_TERMINATOR;
    
    return (index + 1);
}