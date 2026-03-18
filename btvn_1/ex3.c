// Viết một chương trình đếm số khoảng trắng, tab và dấu xuống dòng.
#include <stdio.h>

int main() {
    int c;
    int blanks = 0, tabs = 0, newlines = 0;

    while ((c = getchar()) != 'q') {
        if (c == ' ') ++blanks;
        if (c == '\t') ++tabs;
        if (c == '\n') ++newlines;
    }
    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, tabs, newlines);
    return 0;
}