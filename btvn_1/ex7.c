/*******************************************************************************
 * Description  : Viết một chương trình xóa các khoảng trắng và tab ở cuối mỗi 
 * dòng đầu vào, và xóa hoàn toàn các dòng trống.
 ******************************************************************************/
 /*******************************************************************************
 * Phần lí thuyết liên quan: 
   * - Chuỗi và mảng
   * - Truyền tham chiếu
 ******************************************************************************/

#include <stdio.h>

#define MAX_LINE_LENGTH 1024
#define CHAR_NEWLINE    '\n'
#define CHAR_BLANK      ' '
#define CHAR_TAB        '\t'
#define STRING_TERMINATOR '\0'
#define SIGNAL_EOF      -1

// Các nguyên mẫu hàm
int fetch_line(char *line_buffer, int max_length);
int trim_trailing(char *line_buffer, int current_length);

int main(void)
{
    char line_buffer[MAX_LINE_LENGTH];
    int current_length;

    // Vòng lặp chạy cho đến khi fetch_line trả về -1 (tín hiệu kết thúc file)
    while ((current_length = fetch_line(line_buffer, MAX_LINE_LENGTH)) != SIGNAL_EOF)
    {
        // Cắt bỏ khoảng trắng và tab ở cuối dòng
        current_length = trim_trailing(line_buffer, current_length);
        
        // Chỉ in ra nếu dòng không trống (độ dài > 0)
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

    // Đọc từng ký tự cho đến khi gặp xuống dòng hoặc hết file
    while ((iterator < max_length - 1) && 
           ((current_char = getchar()) != EOF) && 
           (current_char != CHAR_NEWLINE))
    {
        line_buffer[iterator] = (char)current_char;
        iterator++;
    }

    // Nếu gặp EOF ngay từ đầu và không đọc được ký tự nào, trả về tín hiệu kết thúc
    if (current_char == EOF && iterator == 0)
    {
        return SIGNAL_EOF;
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

    // Đặt lại ký tự kết thúc chuỗi tại vị trí mới
    line_buffer[index + 1] = STRING_TERMINATOR;
    
    // Trả về độ dài mới của dòng
    return (index + 1);
}