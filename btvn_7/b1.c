/*******************************************************************************
 * Description  : Bài tập 1: Xây dựng Hash Table với cơ chế Chaining.
 * Viết một chương trình C quản lý danh bạ điện thoại đơn giản bằng bảng băm.
 * Các chức năng bắt buộc: insert, search, delete. Yêu cầu nhập ít nhất 8 liên hệ,
 * tìm kiếm 3 tên (1 tên không tồn tại), xóa 2 liên hệ và in lại bảng.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

// Cấu trúc Node cho danh sách liên kết
struct Node 
{
    char name[50];
    char phone[20];
    struct Node *next;
};

// Khởi tạo mảng các con trỏ buckets (toàn cục)
struct Node *buckets[TABLE_SIZE] = {NULL};

// Hàm băm sử dụng công thức đa thức (nhân với 31)
unsigned int hash(char *str) 
{
    unsigned int hashval = 0;
    for (; *str != '\0'; str++) 
    {
        hashval = *str + 31 * hashval;
    }
    return hashval % TABLE_SIZE;
}

// Hàm thêm một liên hệ mới vào bảng băm
void insert(char *name, char *phone) 
{
    unsigned int index = hash(name);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    
    if (new_node != NULL) 
    {
        strcpy(new_node->name, name);
        strcpy(new_node->phone, phone);
        
        // Chèn vào đầu danh sách liên kết tại bucket
        new_node->next = buckets[index];
        buckets[index] = new_node;
    }
}

// Hàm tìm kiếm theo tên và trả về số điện thoại
char* search(char *name) 
{
    unsigned int index = hash(name);
    struct Node *current;
    
    // Duyệt danh sách liên kết tại bucket
    for (current = buckets[index]; current != NULL; current = current->next) 
    {
        if (strcmp(current->name, name) == 0) 
        {
            return current->phone; 
        }
    }
    return NULL; 
}

// Hàm xóa một liên hệ khỏi bảng băm
void delete_contact(char *name) 
{
    unsigned int index = hash(name);
    struct Node *current = buckets[index];
    struct Node *prev = NULL;

    // Tìm kiếm nút cần xóa
    while (current != NULL && strcmp(current->name, name) != 0) 
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL) 
    {
        if (prev == NULL) 
        {
            // Nút cần xóa nằm ở đầu danh sách
            buckets[index] = current->next;
        } 
        else 
        {
            // Nút cần xóa nằm ở giữa hoặc cuối
            prev->next = current->next;
        }
        free(current);
        printf("Da xoa lien he: %s\n", name);
    }
    else
    {
        printf("Khong tim thay lien he de xoa: %s\n", name);
    }
}

// Hàm in toàn bộ danh bạ
void print_table(void) 
{
    int i;
    struct Node *current;
    
    printf("\n--- Danh ba hien tai ---\n");
    for (i = 0; i < TABLE_SIZE; i++) 
    {
        for (current = buckets[i]; current != NULL; current = current->next) 
        {
            printf("Ten: %-10s - SDT: %s\n", current->name, current->phone);
        }
    }
    printf("------------------------\n");
}

// Hàm giải phóng bộ nhớ
void free_table(void) 
{
    int i;
    struct Node *current;
    struct Node *next_node;

    for (i = 0; i < TABLE_SIZE; i++) 
    {
        current = buckets[i];
        while (current != NULL) 
        {
            next_node = current->next;
            free(current);
            current = next_node;
        }
        buckets[i] = NULL;
    }
}

int main(void) 
{
    char *phone;

    // 1. Nhập thử ít nhất 8 liên hệ
    insert("Alice", "0123456789");
    insert("Bob", "0987654321");
    insert("Charlie", "0111222333");
    insert("David", "0444555666");
    insert("Eve", "0777888999");
    insert("Frank", "0333444555");
    insert("Grace", "0666777888");
    insert("Hannah", "0999000111");

    print_table();

    // 2. Thực hiện tìm kiếm 3 tên (1 tên không tồn tại)
    printf("\n--- Tim kiem ---\n");
    
    phone = search("Bob");
    if (phone != NULL) printf("Tim thay Bob: %s\n", phone);
    else printf("Khong tim thay Bob\n");

    phone = search("Grace");
    if (phone != NULL) printf("Tim thay Grace: %s\n", phone);
    else printf("Khong tim thay Grace\n");

    phone = search("John"); // Tên không tồn tại
    if (phone != NULL) printf("Tim thay John: %s\n", phone);
    else printf("Khong tim thay John\n");

    // 3. Thực hiện xóa 2 liên hệ và in lại
    printf("\n--- Thuc hien xoa ---\n");
    delete_contact("Charlie");
    delete_contact("Eve");
    
    print_table();

    // Dọn dẹp
    free_table();

    return 0;
}