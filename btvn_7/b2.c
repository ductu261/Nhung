/*******************************************************************************
 * Description  : Bài tập 2: Tạo và liên kết thư viện tĩnh/động.
 * File main.c: viết chương trình chính để gọi và kiểm thử thư viện.
 ******************************************************************************/
#include <stdio.h>
// Gọi tệp tiêu đề của thư viện vào
#include "hashtable.h"

int main(void) 
{
    char *phone;

    insert("Alice", "0123456789");
    insert("Bob", "0987654321");
    insert("Charlie", "0111222333");
    insert("David", "0444555666");
    insert("Eve", "0777888999");
    insert("Frank", "0333444555");
    insert("Grace", "0666777888");
    insert("Hannah", "0999000111");

    print_table();

    printf("\n--- Tim kiem ---\n");
    phone = search("Bob");
    if (phone != NULL) printf("Tim thay Bob: %s\n", phone);

    phone = search("John"); 
    if (phone == NULL) printf("Khong tim thay John\n");

    printf("\n--- Thuc hien xoa ---\n");
    delete_contact("Charlie");
    delete_contact("Eve");
    
    print_table();

    free_table();

    return 0;
}