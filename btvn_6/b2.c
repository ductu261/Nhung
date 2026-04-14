/*******************************************************************************
 * Description  : Thêm khả năng tìm kiếm theo trường, để việc sắp xếp có thể 
 * được thực hiện trên các trường trong các dòng, mỗi trường được sắp 
 * xếp theo một tập hợp các tùy chọn độc lập[cite: 180, 181].
 * (Vì việc xây dựng lại toàn bộ chương trình sort của hệ điều hành rất 
 * dài, dưới đây là phiên bản cơ bản mô phỏng việc chia một bản ghi 
 * thành các trường và có các tùy chọn sắp xếp độc lập cho từng trường).
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Cấu trúc mô phỏng một dòng dữ liệu được chia thành các trường
struct record 
{
    char category[MAX_STR_LEN]; // Trường 1: Sắp xếp theo chuỗi (vd: -df)
    int page_number;            // Trường 2: Sắp xếp theo số (vd: -n)
};

// Hàm tùy chọn 1: Sắp xếp theo trường category (chữ cái)
int sort_by_category(const void *a, const void *b) 
{
    struct record *recA = (struct record *)a;
    struct record *recB = (struct record *)b;
    return strcmp(recA->category, recB->category);
}

// Hàm tùy chọn 2: Sắp xếp theo trường page_number (số nguyên)
int sort_by_page_number(const void *a, const void *b) 
{
    struct record *recA = (struct record *)a;
    struct record *recB = (struct record *)b;
    return recA->page_number - recB->page_number;
}

int main(void) 
{
    int i;
    struct record index_data[] = {
        {"Function pointers", 118},
        {"Arrays", 97},
        {"Pointers", 93}
    };
    int num_records = 3;

    printf("--- Sap xep theo Truong 1 (Category - Chuoi) ---\n");
    qsort(index_data, num_records, sizeof(struct record), sort_by_category);
    for (i = 0; i < num_records; i++) 
    {
        printf("%-20s : %d\n", index_data[i].category, index_data[i].page_number);
    }

    printf("\n--- Sap xep theo Truong 2 (Page Number - So) ---\n");
    qsort(index_data, num_records, sizeof(struct record), sort_by_page_number);
    for (i = 0; i < num_records; i++) 
    {
        printf("%-20s : %d\n", index_data[i].category, index_data[i].page_number);
    }

    return 0;
}