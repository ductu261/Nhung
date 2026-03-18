#include <stdio.h>
#include <string.h>

// Hàm đảo ngược chuỗi (giữ nguyên từ bài trước)
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// Hàm itob: Chuyển số nguyên n thành chuỗi s theo cơ số b
void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n; // Lưu lại dấu ban đầu của n
    int digit;

    // Kiểm tra cơ số hợp lệ (chỉ hỗ trợ từ base 2 đến base 36)
    if (b < 2 || b > 36) {
        s[0] = '\0';
        return;
    }

    do {
        // Lấy phần dư
        digit = n % b;
        
        // Trị tuyệt đối phần dư để xử lý trường hợp n là số âm
        if (digit < 0) {
            digit = -digit;
        }
        
        // Chuyển phần dư thành ký tự ASCII tương ứng
        if (digit <= 9) {
            s[i++] = digit + '0'; // Các số từ 0-9
        } else {
            s[i++] = digit - 10 + 'A'; // Các số từ 10 trở lên thành A, B, C...
        }
        
    } while ((n /= b) != 0); // Tiếp tục chia cho cơ số b

    // Thêm dấu '-' nếu số ban đầu là số âm
    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i] = '\0'; // Chốt kết thúc chuỗi
    
    reverse(s); // Đảo ngược chuỗi để có kết quả đúng
}

int main() {
    char buffer[50];
    int test_val = 255;
    int neg_val = -255;

    itob(test_val, buffer, 16);
    printf("So %d o he Hex (base 16) la: %s\n", test_val, buffer);
    
    itob(test_val, buffer, 2);
    printf("So %d o he Binary (base 2) la: %s\n", test_val, buffer);

    itob(neg_val, buffer, 16);
    printf("So %d o he Hex (base 16) la: %s\n", neg_val, buffer);

    return 0;
}