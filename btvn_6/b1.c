#include <stdio.h>
#include <string.h>

int strend(const char *s, const char *t) {
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    // Nếu chuỗi t dài hơn chuỗi s thì không thể nằm ở cuối
    if (len_t > len_s) {
        return 0;
    }

    // So sánh phần cuối của s với t
    // s + len_s - len_t là con trỏ dời đến vị trí bắt đầu kiểm tra
    if (strcmp(s + len_s - len_t, t) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("%d\n", strend("Hello World", "World")); // In ra 1
    printf("%d\n", strend("Hello World", "Word"));  // In ra 0
    return 0;
}