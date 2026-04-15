/*******************************************************************************
 * Description  : Trong biểu diễn số bù 2, phiên bản itoa không xử lý được số âm 
 * lớn nhất, tức là giá trị n bằng -(2^(wordsize-1)). Giải thích tại 
 * sao không. Sửa đổi nó để in giá trị đó chính xác, bất kể máy nào 
 * đang chạy nó.
 * (Giải thích: Số âm lớn nhất không thể lưu vừa trong một biến dương có 
 * cùng kích thước, việc đảo dấu bằng n = -n sẽ gây tràn bộ nhớ.)
 ******************************************************************************/
 /*******************************************************************************
 * Phần lí thuyết liên quan: 
   * - Kiểu dữ liệu và Giới hạn biểu diễn (Data Types & Limits)
   * - Cấu trúc lặp (Iterative blocks)
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define BASE_10 10

// Hàm đảo ngược chuỗi
void reverse(char s[]) 
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) 
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[]) 
{
    int i = 0;
    int sign = n;

    // Xử lý từng chữ số bằng phép chia dư, hoạt động đúng cho số âm
    do 
    {
        int digit = n % BASE_10;
        
        // Đảm bảo chữ số luôn dương
        if (digit < 0) 
        {
            digit = -digit;
        }
        s[i++] = digit + '0';
    } while ((n /= BASE_10) != 0);

    // Thêm dấu trừ nếu là số âm
    if (sign < 0) 
    {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char buffer[50];
    int min_int = INT_MIN; 
    
    itoa(min_int, buffer);
    printf("Gia tri dau vao (INT_MIN): %d\n", min_int);
    printf("Chuoi sau khi dung itoa  : %s\n", buffer);

    return 0;
}