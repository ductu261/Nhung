#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100 // Kích thước mảng băm giả định

// Cấu trúc một Node trong danh sách liên kết
typedef struct Node {
    char word[100];
    int count;
    struct Node* next;
} Node;

// Khởi tạo bảng băm
Node* hashtable[HASH_SIZE] = {NULL};

// Hàm băm đơn giản cho chuỗi (djb2 hoặc tương tự)
unsigned int hash_func(const char* word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash * 31) + *word;
        word++;
    }
    return hash % HASH_SIZE;
}

// 1. Hoàn thiện hàm lookup()
Node* lookup(const char* word, int create_if_not_found) {
    unsigned int index = hash_func(word);
    Node* current = hashtable[index];

    // Duyệt danh sách liên kết tại vị trí index
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current; // Đã tìm thấy từ
        }
        current = current->next;
    }

    // Nếu không tìm thấy và có cờ yêu cầu tạo mới
    if (create_if_not_found) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) return NULL; // Lỗi cấp phát
        
        strcpy(new_node->word, word);
        new_node->count = 0; 
        
        // Chèn vào đầu danh sách liên kết
        new_node->next = hashtable[index];
        hashtable[index] = new_node;
        
        return new_node;
    }

    return NULL; // Không tìm thấy và không tạo mới
}

// 2. Hoàn thiện hàm cleartable() để giải phóng toàn bộ bộ nhớ
void cleartable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashtable[i];
        while (current != NULL) {
            Node* temp = current; // Lưu lại node hiện tại
            current = current->next; // Chuyển sang node tiếp theo
            free(temp); // Giải phóng bộ nhớ của node hiện tại
        }
        hashtable[i] = NULL; // Reset con trỏ trong mảng
    }
}
int main() {
    // Mở file book.txt để đọc
    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Lỗi: Không thể mở file 'book.txt'. Vui lòng tạo file này trước.\n");
        return 1;
    }

    char word[100];
    
    // Đọc từng từ từ file cho đến khi kết thúc (EOF)
    // Giới hạn đọc tối đa 99 ký tự để tránh tràn bộ đệm cho mảng char word[100]
    while (fscanf(file, "%99s", word) == 1) {
        // Tìm kiếm từ trong bảng băm, nếu chưa có thì tạo mới (tham số thứ hai = 1)
        Node* node = lookup(word, 1);
        
        if (node != NULL) {
            // Tăng biến đếm tần suất xuất hiện của từ
            node->count++; 
        }
    }
    
    // Đóng file sau khi đọc xong
    fclose(file);

    // In ra kết quả tần suất của các từ đã lưu trong bảng băm để kiểm tra
    printf("Tần suất xuất hiện của các từ:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashtable[i];
        while (current != NULL) {
            printf("- %s: %d\n", current->word, current->count);
            current = current->next;
        }
    }

    // Dọn dẹp bộ nhớ sau khi sử dụng xong
    cleartable();
    printf("\nĐã giải phóng bộ nhớ bảng băm thành công.\n");

    return 0;
}