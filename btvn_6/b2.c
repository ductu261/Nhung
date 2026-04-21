/*******************************************************************************
 * Description  : Thêm khả năng tìm kiếm theo trường, để việc sắp xếp có thể 
 * được thực hiện trên các trường trong các dòng, mỗi trường được sắp 
 * xếp theo một tập hợp các tùy chọn độc lập.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 1. CHỨC NĂNG TÌM KIẾM TRƯỜNG 

void get_field(const char *line, int field_num, char *result) 
{
    int current_field = 1;
    int i = 0, j = 0;

    while (line[i] != '\0') 
    {
        // Bỏ qua các khoảng trắng thừa
        while (line[i] == ' ' || line[i] == '\t') i++;

        if (line[i] == '\0') break;

        // Nếu đúng cột cần tìm, copy các ký tự vào result
        if (current_field == field_num) 
        {
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') 
            {
                result[j++] = line[i++];
            }
            result[j] = '\0';
            return;
        }

        // Nếu chưa tới cột cần tìm, bỏ qua từ này
        while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') i++;
        current_field++;
    }
    result[0] = '\0'; // Trả về rỗng nếu không tìm thấy
}

// 2. LUẬT SẮP XẾP RIÊNG BIỆT 

int cmp_df(const char *s1, const char *s2) 
{
    while (*s1 && *s2) 
    {
        // -d: Bỏ qua ký tự đặc biệt (chỉ lấy chữ cái, chữ số, khoảng trắng)
        while (*s1 && !isalnum(*s1) && *s1 != ' ') s1++;
        while (*s2 && !isalnum(*s2) && *s2 != ' ') s2++;

        if (*s1 == '\0' || *s2 == '\0') break;

        // -f: Chuyển hết thành chữ thường để so sánh
        char c1 = tolower(*s1);
        char c2 = tolower(*s2);

        if (c1 != c2) return c1 - c2;

        s1++;
        s2++;
    }
    return 0; // Trả về 0 nếu hòa nhau
}

// 3. HÀM SO SÁNH TỔNG (Truyền vào qsort)
int master_compare(const void *a, const void *b) 
{
    const char *lineA = *(const char **)a;
    const char *lineB = *(const char **)b;

    char fieldA[100], fieldB[100];

    get_field(lineA, 1, fieldA);
    get_field(lineB, 1, fieldB);
    
    int result = cmp_df(fieldA, fieldB);
    
    if (result == 0) 
    {
        get_field(lineA, 2, fieldA);
        get_field(lineB, 2, fieldB);
        
        // Ép chuỗi sang số nguyên (hành vi của cờ -n)
        return atoi(fieldA) - atoi(fieldB);
    }

    return result;
}

int main(void) 
{
    // Dữ liệu thô (Raw text lines) giống hệt một file văn bản
    const char *lines[] = {
        "Variables      115",
        "Arrays         20",
        "arrays!        15",
        "Pointers       50"
    };
    int num_lines = sizeof(lines) / sizeof(lines[0]);

    printf("--- Truoc khi sap xep ---\n");
    for (int i = 0; i < num_lines; i++) 
    {
        printf("%s\n", lines[i]);
    }

    // Thực thi sắp xếp
    qsort(lines, num_lines, sizeof(char *), master_compare);

    printf("\n--- Sau khi sap xep (Cot 1: -df, Cot 2: -n) ---\n");
    for (int i = 0; i < num_lines; i++) 
    {
        printf("%s\n", lines[i]);
    }

    return 0;
}