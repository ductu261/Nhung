// Viết một hàm htoi(s), chuyển đổi một chuỗi các chữ số thập lục phân (bao gồm cả 0x hoặc 0X tùy chọn ở đầu) thành giá trị số nguyên (integer) tương đương. Các ký tự hợp lệ là 0 đến 9, a đến f, và A đến F.
#include <stdio.h>

// Hàm htoi: Chuyển chuỗi Hex sang số nguyên
int htoi(const char s[]) {
    int i = 0;
    int n = 0;
    int in_hex;

    // Bỏ qua tiền tố "0x" hoặc "0X" nếu có
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
        i = i + 2;
    }

    in_hex = 1;
    for (; in_hex == 1; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a' + 10);
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        } else {
            in_hex = 0; // Ký tự không hợp lệ, dừng vòng lặp
        }
    }
    return n;
}

int main() {
    // Các trường hợp kiểm thử (Test cases)
    const char *test1 = "0x1A";    // Hệ 10: 26
    const char *test2 = "0XFF";    // Hệ 10: 255
    const char *test3 = "100";     // Hệ 10: 256 (Không có tiền tố vẫn hiểu là hex theo thuật toán)
    const char *test4 = "0xabc";   // Hệ 10: 2748
    const char *test5 = "0x1G3";   // Ký tự G không hợp lệ, sẽ dừng ở 1 -> Kết quả: 1

    printf("Chuoi: %8s -> So nguyen: %d\n", test1, htoi(test1));
    printf("Chuoi: %8s -> So nguyen: %d\n", test2, htoi(test2));
    printf("Chuoi: %8s -> So nguyen: %d\n", test3, htoi(test3));
    printf("Chuoi: %8s -> So nguyen: %d\n", test4, htoi(test4));
    printf("Chuoi: %8s -> So nguyen: %d\n", test5, htoi(test5));

    return 0;
}