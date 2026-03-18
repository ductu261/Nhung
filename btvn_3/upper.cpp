#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int c;

    // strstr là hàm tìm chuỗi con. Nó trả về NULL nếu không tìm thấy.
    // cả đường dẫn hệ thống (ví dụ: "./lower" hoặc "C:\\bin\\lower.exe")
    if (strstr(argv[0], "lower") != NULL) {
        
        // Liên tục đọc ký tự và chuyển thành in thường
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
        
    } else if (strstr(argv[0], "upper") != NULL) {
        
        // Liên tục đọc ký tự và chuyển thành in hoa
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
        
    } else {
        // Nếu tên file không chứa lower cũng không chứa upper
        printf("Loi: Vui long doi ten file chay thanh 'lower' hoac 'upper'.\n");
        printf("Ten hien tai cua chuong trinh la: %s\n", argv[0]);
        return 1; // Trả về mã lỗi 1 cho hệ điều hành biết chương trình chạy thất bại
    }

    return 0; // Trả về 0 báo hiệu chương trình kết thúc thành công
}