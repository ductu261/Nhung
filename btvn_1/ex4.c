//Viết chương trình sao chép input ra output, thay thế một chuỗi có một hoặc nhiều khoảng trắng bằng một khoảng trắng duy nhất
#include <stdio.h>

int main() {
    int c;
    int in_space = 0;

    while ((c = getchar()) != 'q') {
        if (c == ' ') {
            if (!in_space) {
                putchar(c);
                in_space = 1;
            }
        } else {
            putchar(c);
            in_space = 0;
        }
    }
    return 0;
}