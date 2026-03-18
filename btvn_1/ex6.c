// Viết chương trình in ra tần suất của các ký tự khác nhau trong input
#include <stdio.h>

int main() {
    int c;
    int char_counts[128] = {0}; // Mảng đếm các ký tự ASCII

    while ((c = getchar()) != 'q') {
        if (c >= 0 && c < 128) {
            char_counts[c]++;
        }
    }

    printf("Character Frequencies:\n");
    for (int i = 32; i < 126; ++i) { // Chỉ in các ký tự có thể hiển thị
        if (char_counts[i] > 0) {
            printf("'%c': %d\n", i, char_counts[i]);
        }
    }
    return 0;
}