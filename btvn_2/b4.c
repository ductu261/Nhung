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
    int sign = n;
    int digit;

    // Trích xuất từng chữ số theo cơ số b
    do 
    {
        digit = n % b;
        
        if (digit < 0) 
        {
            digit = -digit;
        }
        
        // Xử lý các chữ số cho hệ cơ số lớn hơn 10 (vd: a-f)
        if (digit <= 9) 
        {
            s[i++] = digit + '0';
        } 
        else 
        {
            s[i++] = digit - 10 + 'a';
        }
    } while ((n /= b) != 0);

    // Thông thường dấu trừ chỉ áp dụng cho hệ thập phân
    if (sign < 0 && b == 10) 
    {
        s[i++] = '-';
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