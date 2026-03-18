//Viết chương trình loại bỏ các khoảng trắng và tab thừa ở cuối mỗi dòng input, và xóa hoàn toàn các dòng trống.
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        // Cắt khoảng trắng và tab ở cuối
        while (len > 0 && (line[len-1] == ' ' || line[len-1] == '\t' || line[len-1] == '\n')) {
            len--;
        }
        if (len > 0) { // Nếu dòng không trống
            line[len] = '\n';
            line[len+1] = '\0';
            printf("%s", line);
        }
    }
    return 0;
}

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
