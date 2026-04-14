/*******************************************************************************
 * Description  : Viết hàm strend(s,t), trả về 1 nếu chuỗi t xuất hiện ở cuối 
 * của chuỗi s, và trả về 0 nếu ngược lại[cite: 179].
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) 
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    // Nếu chuỗi t dài hơn chuỗi s thì t không thể nằm ở cuối s
    if (len_t > len_s) 
    {
        return 0;
    }

    // Dời con trỏ của s đến vị trí bắt đầu so sánh và dùng strcmp
    if (strcmp(s + len_s - len_t, t) == 0) 
    {
        return 1;
    }

    return 0;
}

int main(void) 
{
    char chuoi_goc[] = "lap trinh c co ban";
    char chuoi_tim1[] = "co ban";
    char chuoi_tim2[] = "lap trinh";

    printf("Tim '%s' o cuoi '%s': %d\n", chuoi_tim1, chuoi_goc, strend(chuoi_goc, chuoi_tim1)); // Ky vong: 1
    printf("Tim '%s' o cuoi '%s': %d\n", chuoi_tim2, chuoi_goc, strend(chuoi_goc, chuoi_tim2)); // Ky vong: 0

    return 0;
}