/*******************************************************************************
 * Description  : Viết một hàm expand(s1,s2) mở rộng các ký hiệu viết tắt như a-z 
 * trong chuỗi s1 thành danh sách hoàn chỉnh abc...xyz trong s2. 
 * Cho phép chữ cái ở cả hai dạng và chữ số, xử lý các trường hợp như 
 * a-b-c, a-z0-9 và -a-z. Sắp xếp để dấu - ở đầu hoặc cuối được lấy 
 * theo nghĩa đen.
 ******************************************************************************/
#include <stdio.h>

void expand(char s1[], char s2[]) 
{
    int i = 0;
    int j = 0;
    int current_char;

    // Duyệt qua từng ký tự của chuỗi đầu vào
    while ((current_char = s1[i++]) != '\0') 
    {
        // Kiểm tra xem có phải định dạng viết tắt không
        if ((s1[i] == '-') && (s1[i + 1] >= current_char)) 
        {
            i++; // Bỏ qua dấu '-'
            
            // Điền các ký tự ở giữa vào chuỗi s2
            while (current_char < s1[i]) 
            {
                s2[j++] = current_char++;
            }
        } 
        else 
        {
            s2[j++] = current_char;
        }
    }
    
    s2[j] = '\0';
}

int main(void)
{
    char result[100];

    expand("a-z", result);
    printf("expand(\"a-z\")   -> %s\n", result);

    expand("-a-c0-3-", result);
    printf("expand(\"-a-c0-3-\") -> %s\n", result);

    return 0;
}