/*******************************************************************************
 * Description  : Viết một chương trình in ra biểu đồ tần suất của các ký tự 
 * khác nhau trong đầu vào của nó.
 ******************************************************************************/
 /*******************************************************************************
 * Phần lí thuyết liên quan: 
    * - Thư viện nhập xuất chuẩn: stdio.h, sử dụng hàm getchar() để đọc từng ký tự từ đầu vào.
    * - Vòng lặp while và kiến trúc rẽ nhánh if-else để phân loại và đếm các ký tự.
    * - Toán tử quan hệ ( == , != ) và toán tử gán 
    * - Preprocessor Macros: #define
    * - Biến và kiểu dữ liệu
    * - Mảng 
    * - Vòng lặp lồng nhau để in biểu đồ
    * - Toán tử logic
    * - Ép kiểu
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

#define ASCII_MAX_CHARS 128
#define HISTOGRAM_BAR   '*'

int main(void)
{
    int current_char;
    int char_frequencies[ASCII_MAX_CHARS] = {0};
    int i, j;

    // Thu thập tần suất xuất hiện của từng ký tự ASCII
    while ((current_char = getchar()) != EOF)
    {
        if (current_char >= 0 && current_char < ASCII_MAX_CHARS)
        {
            char_frequencies[current_char]++;
        }
    }

    // In biểu đồ ngang cho các ký tự có thể in được
    for (i = 0; i < ASCII_MAX_CHARS; i++)
    {
        if ((char_frequencies[i] > 0) && isprint(i))
        {
            printf("'%c' | ", (char)i);
            
            for (j = 0; j < char_frequencies[i]; j++)
            {
                putchar(HISTOGRAM_BAR);
            }
            putchar('\n');
        }
    }

    return 0;
}