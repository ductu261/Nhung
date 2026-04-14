/*******************************************************************************
 * Description  : Viết một chương trình chuyển đổi chữ hoa thành chữ thường hoặc 
 * chữ thường thành chữ hoa, phụ thuộc vào tên mà nó được gọi, được tìm thấy 
 * trong argv[0].
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int current_char;
    
    // Kiểm tra xem tên chương trình có chứa từ "lower" hay không
    if (strstr(argv[0], "lower") != NULL) 
    {
        // Chuyển toàn bộ thành chữ thường
        while ((current_char = getchar()) != EOF) 
        {
            putchar(tolower(current_char));
        }
    } 
    else 
    {
        // Mặc định chuyển toàn bộ thành chữ hoa
        while ((current_char = getchar()) != EOF) 
        {
            putchar(toupper(current_char));
        }
    }
    
    return 0;
}