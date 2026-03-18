#include <stdio.h>

#define MAXLINE 100
#define PAGELEN 20   // số dòng mỗi trang

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAXLINE];
    int lineno, pageno;

    if (argc < 2) {
        printf("Usage: print file1 file2 ...\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {

        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Khong mo duoc file %s\n", argv[i]);
            continue;
        }

        lineno = 0;
        pageno = 1;

        printf("\n===== File: %s | Page %d =====\n\n", argv[i], pageno);

        while (fgets(line, MAXLINE, fp) != NULL) {

            printf("%s", line);
            lineno++;

            if (lineno == PAGELEN) {
                pageno++;
                lineno = 0;

                printf("\f");   // page break
                printf("\n===== File: %s | Page %d =====\n\n", argv[i], pageno);
            }
        }

        fclose(fp);
    }

    return 0;
}