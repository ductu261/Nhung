/*******************************************************************************
 * Description  : Bài tập 2: Tạo và liên kết thư viện tĩnh/động.
 * File hashtable.h: khai báo các kiểu dữ liệu, hằng số và nguyên mẫu hàm.
 ******************************************************************************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 101

// Cấu trúc Node
struct Node 
{
    char name[50];
    char phone[20];
    struct Node *next;
};

// Nguyên mẫu các hàm
unsigned int hash(char *str);
void insert(char *name, char *phone);
char* search(char *name);
void delete_contact(char *name);
void print_table(void);
void free_table(void);

#endif