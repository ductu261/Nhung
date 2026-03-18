#include <stdio.h>
#include <string.h>

// Hàm đảo ngược chuỗi (cần thiết cho itoa vì ta lấy ra từ hàng đơn vị trước)
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// Hàm itoa đã được nâng cấp
void itoa(int n, char s[]) {
    int i = 0;
    int sign = n; // Lưu lại dấu ban đầu của n

    do {
        // Lấy phần dư (digit). Nếu n âm, digit sẽ âm.
        int digit = n % 10;
        
        // Trị tuyệt đối phần dư để chuyển thành ký tự hợp lệ
        if (digit < 0) {
            digit = -digit;
        }
        
        // Chuyển số thành mã ASCII và lưu vào mảng
        s[i++] = digit + '0';
        
    } while ((n /= 10) != 0); // Quan trọng: Dùng != 0 thay vì > 0 vì n có thể đang là số âm

    // Nếu ban đầu là số âm, thêm dấu '-' vào
    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i] = '\0'; // Chốt đuôi chuỗi
    
    reverse(s);  // Lật ngược chuỗi lại cho đúng thứ tự
}

int main() {
    char buffer[20];
    // Thử nghiệm với số âm nhỏ nhất của kiểu int 32-bit: -2147483648
    int min_int = -2147483648; 
    
    itoa(min_int, buffer);
    printf("Ket qua chuyen doi: %s\n", buffer);
    
    return 0;
}