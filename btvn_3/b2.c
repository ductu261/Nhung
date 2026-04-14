/*******************************************************************************
 * Description  : Viết một chương trình so sánh hai file, in ra dòng đầu tiên 
 * nơi chúng khác nhau.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) 
{
    FILE *file1;
    FILE *file2;
    char line1[MAX_LINE_LEN];
    char line2[MAX_LINE_LEN];
    char *ptr1;
    char *ptr2;

    // Yêu cầu phải có đủ tên 2 file truyền vào
    if (argc != 3) 
    {
        printf("Su dung: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    file1 = fopen(argv[1], "r");
    if (file1 == NULL) 
    {
        printf("Loi: Khong the mo %s\n", argv[1]);
        return 1;
    }

    file2 = fopen(argv[2], "r");
    if (file2 == NULL) 
    {
        printf("Loi: Khong the mo %s\n", argv[2]);
        fclose(file1);
        return 1;
    }

    // Đọc và so sánh từng dòng
    do 
    {
        ptr1 = fgets(line1, MAX_LINE_LEN, file1);
        ptr2 = fgets(line2, MAX_LINE_LEN, file2);

        // Phát hiện khác biệt khi cả 2 file đều còn dữ liệu
        if ((ptr1 != NULL) && (ptr2 != NULL) && (strcmp(line1, line2) != 0)) 
        {
            printf("Khac biet tai dong:\n");
            printf("%s: %s", argv[1], line1);
            printf("%s: %s", argv[2], line2);
            break;
        }
        // File 1 dài hơn File 2
        else if ((ptr1 != NULL) && (ptr2 == NULL)) 
        {
            printf("Khac biet: %s dai hon %s\n", argv[1], argv[2]);
            break;
        }
        // File 2 dài hơn File 1
        else if ((ptr1 == NULL) && (ptr2 != NULL)) 
        {
            printf("Khac biet: %s dai hon %s\n", argv[2], argv[1]);
            break;
        }
    } while ((ptr1 != NULL) && (ptr2 != NULL));

    fclose(file1);
    fclose(file2);

    return 0;
}