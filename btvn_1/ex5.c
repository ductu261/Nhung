//Viết chương trình sao chép input ra output, thay thế mỗi tab bằng \t, mỗi backspace bằng \b, và mỗi backslash bằng \\. Việc này giúp các ký tự ẩn hiện rõ một cách không mơ hồ.
#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != 'q') {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");klkjwh
        } else {
            putchar(c);
        }
    }
    return 0;
}