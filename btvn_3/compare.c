#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]) {

    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    int lineno = 1;

    if (argc != 3) {
        printf("Usage: compare file1 file2\n");
        return 1;
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Loi mo file!\n");
        return 1;
    }

    while (1) {

        char *p1 = fgets(line1, MAXLINE, fp1);
        char *p2 = fgets(line2, MAXLINE, fp2);

        // nếu cả hai đều hết file
        if (p1 == NULL && p2 == NULL) {
            printf("Hai file giong nhau.\n");
            break;
        }

        // nếu khác nhau
        if (p1 == NULL || p2 == NULL || strcmp(line1, line2) != 0) {
            printf("Khac nhau tai dong %d:\n", lineno);

            printf("File1: %s", p1 ? line1 : "(EOF)\n");
            printf("File2: %s", p2 ? line2 : "(EOF)\n");

            break;
        }

        lineno++;
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}