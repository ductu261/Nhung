/*******************************************************************************
 * Description  : Viết một chương trình sao chép đầu vào ra đầu ra, thay thế mỗi 
 * chuỗi có một hoặc nhiều khoảng trắng bằng một khoảng trắng duy nhất.
 ******************************************************************************/
/*******************************************************************************
 * Phần lí thuyết liên quan: 
    * - Thư viện nhập xuất chuẩn: stdio.h, sử dụng hàm getchar() để đọc từng ký tự từ đầu vào.
    * - Vòng lặp while và kiến trúc rẽ nhánh if-else để phân loại và đếm các ký tự.
    * - Toán tử quan hệ ( == , != ) và toán tử gán 
    * - Preprocessor Macros: #define
    * - Biến và kiểu dữ liệu
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define CHAR_BLANK ' '

int main(void)
{
    int current_char;
    bool was_previous_blank = false;

    // Đọc và xử lý từng ký tự từ đầu vào
    while ((current_char = getchar()) != EOF)
    {
        if (current_char == CHAR_BLANK)
        {
            // Chỉ in ra nếu ký tự trước đó không phải là khoảng trắng
            if (!was_previous_blank)
            {
                putchar(current_char);
                was_previous_blank = true;
            }
        }
        else
        {
            putchar(current_char);
            was_previous_blank = false;
        }
    }

    return 0;
}