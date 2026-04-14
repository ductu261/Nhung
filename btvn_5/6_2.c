/*******************************************************************************
 * Description  : Cài đặt một bảng băm (hash table) với phương pháp chaining 
 * (mảng các danh sách liên kết) để lưu trữ tần suất của các từ.
 * - Hoàn thành hàm lookup() trả về con trỏ đến bản ghi chứa chuỗi. 
 * Nếu không tìm thấy, trả về NULL hoặc tạo một bản ghi mới.
 * - Hoàn thành hàm cleartable() để thu hồi bộ nhớ, đảm bảo mỗi 
 * malloc() đều đi kèm với một lệnh free().
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101

struct node 
{
    char word[100];
    int count;
    struct node *next;
};

// Khởi tạo bảng băm rỗng (mảng các con trỏ)
struct node *hashtable[HASH_SIZE] = {NULL};

// Hàm băm đơn giản: tính tổng các ký tự rồi chia lấy dư
int hash_function(char *s) 
{
    int hashval = 0;
    
    for (hashval = 0; *s != '\0'; s++) 
    {
        hashval = *s + 31 * hashval;
    }
    
    return abs(hashval % HASH_SIZE);
}

// Hàm tìm kiếm và thêm mới nếu chưa tồn tại
struct node *lookup(char *s) 
{
    struct node *np;
    int hashval = hash_function(s);

    // Duyệt danh sách liên kết tại vị trí băm
    for (np = hashtable[hashval]; np != NULL; np = np->next) 
    {
        if (strcmp(s, np->word) == 0) 
        {
            return np; // Đã tìm thấy
        }
    }

    // Không tìm thấy, tiến hành tạo mới
    np = (struct node *)malloc(sizeof(struct node));
    if (np == NULL) 
    {
        return NULL;
    }

    strcpy(np->word, s);
    np->count = 0;
    
    // Chèn vào đầu danh sách liên kết
    np->next = hashtable[hashval];
    hashtable[hashval] = np;

    return np;
}

// Hàm xóa toàn bộ bảng băm và giải phóng bộ nhớ
void cleartable(void) 
{
    int i;
    struct node *np;
    struct node *next_node;

    for (i = 0; i < HASH_SIZE; i++) 
    {
        np = hashtable[i];
        
        while (np != NULL) 
        {
            next_node = np->next; // Lưu lại nút kế tiếp
            free(np);             // Giải phóng nút hiện tại
            np = next_node;       // Chuyển sang nút kế tiếp
        }
        
        hashtable[i] = NULL;      // Đặt lại con trỏ mảng về NULL
    }
}

int main(void) 
{
    struct node *record;
    
    // Thêm một số từ vào bảng băm để kiểm thử
    record = lookup("hello");
    if (record != NULL) record->count++;
    
    record = lookup("world");
    if (record != NULL) record->count++;
    
    record = lookup("hello");
    if (record != NULL) record->count++;

    // Kiểm tra kết quả lưu trữ
    record = lookup("hello");
    if (record != NULL) 
    {
        printf("Tu '%s' xuat hien %d lan.\n", record->word, record->count);
    }

    record = lookup("world");
    if (record != NULL) 
    {
        printf("Tu '%s' xuat hien %d lan.\n", record->word, record->count);
    }

    // Dọn dẹp bộ nhớ
    cleartable();
    printf("Da xoa sach bang bam.\n");

    return 0;
}