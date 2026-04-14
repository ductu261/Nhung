/*******************************************************************************
 * Description  : Viết một chương trình sao chép đầu vào ra đầu ra, thay thế mỗi 
 * tab bằng \t, mỗi backspace bằng \b, và mỗi backslash bằng \\.
 ******************************************************************************/
 /*******************************************************************************
 * Phần lí thuyết liên quan: 
    * - Thư viện nhập xuất chuẩn: stdio.h, sử dụng hàm getchar() để đọc từng ký tự từ đầu vào.
    * - Vòng lặp while và kiến trúc rẽ nhánh if-else để phân loại và đếm các ký tự.
    * - Toán tử quan hệ ( == , != ) và toán tử gán 
    * - Preprocessor Macros: #define
    * - Biến và kiểu dữ liệu
    * - Ký tự Escape 
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