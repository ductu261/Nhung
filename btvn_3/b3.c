/*******************************************************************************
 * Description  : Viết một chương trình in ra một tập hợp các file, bắt đầu 
 * mỗi file mới trên một trang mới, với một tiêu đề và số đếm trang chạy 
 * liên tục cho mỗi file.
 ******************************************************************************/
#include <stdio.h>

#define LINES_PER_PAGE 50
#define PAGE_BREAK_CHAR '\f'
int page_count = 1;
void print_file_with_pagination(FILE *file, char *filename) 
{
    int current_char;
    int line_count = 0;
    

    // In tiêu đề trang đầu
    printf("%c\n--- File: %s | Trang: %d ---\n\n", PAGE_BREAK_CHAR, filename, page_count);

    // Đọc và đếm số dòng để ngắt trang
    while ((current_char = fgetc(file)) != EOF) 
    {
        putchar(current_char);
        
        if (current_char == '\n') 
        {
            line_count++;
            
            // Chuyển trang mới khi đủ số dòng
            if (line_count >= LINES_PER_PAGE) 
            {
                page_count++;
                printf("\n%c\n--- File: %s | Trang: %d ---\n\n", PAGE_BREAK_CHAR, filename, page_count);
                line_count = 0;
            }
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) 
{
    int i;
    FILE *file_ptr;

    if (argc < 2) 
    {
        printf("Su dung: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    // Lặp qua tất cả các file được truyền vào từ command line
    for (i = 1; i < argc; i++) 
    {
        file_ptr = fopen(argv[i], "r");
        if (file_ptr != NULL) 
        {
            print_file_with_pagination(file_ptr, argv[i]);
            fclose(file_ptr);
            page_count++;
        } 
        else 
        {
            printf("Loi: Khong the mo file %s\n", argv[i]);
        }
    }

    return 0;
}