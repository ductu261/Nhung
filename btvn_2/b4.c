/*******************************************************************************
 * Description  : Viết hàm itob(n,s,b) chuyển đổi số nguyên n thành biểu diễn 
 * ký tự cơ số b trong chuỗi s. Cụ thể, itob(n,s,16) định dạng s 
 * thành số nguyên thập lục phân.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

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

void itob(int n, char s[], int b) 
{
    int i = 0;
    
    // TRƯỜNG HỢP 1: Hệ 10 (Xử lý theo kiểu Toán học)
    if (b == 10) 
    {
        int sign = n;
        do 
        {
            int digit = n % 10;
            if (digit < 0) digit = -digit;
            s[i++] = digit + '0';
        } while ((n /= 10) != 0);

        if (sign < 0) s[i++] = '-';
    }
    // TRƯỜNG HỢP 2: Các hệ cơ số khác (Xử lý theo kiểu Bit Bù 2)
    else 
    {
        unsigned int un = (unsigned int)n; 
        do 
        {
            int digit = un % b;
            if (digit <= 9) s[i++] = digit + '0';
            else            s[i++] = digit - 10 + 'a';
        } while ((un /= b) != 0);
        
        // Không thêm dấu trừ ở đây, vì biểu diễn bit tự mang ý nghĩa của nó
    }
    
    s[i] = '\0';
    reverse(s); 
}

int main(void)
{
    char buffer[50];
    int num = 255;

    itob(num, buffer, 16);
    printf("So %d o he 16 la: %s\n", num, buffer);

    itob(num, buffer, 2);
    printf("So %d o he 2  la: %s\n", num, buffer);

    return 0;
}