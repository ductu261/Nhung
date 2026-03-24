#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
struct node {
    int data;
    struct node *next;
};

// (a) Hiển thị danh sách
void display(struct node *head) {
    struct node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// (b) Thêm vào cuối danh sách
struct node* addback(struct node *head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// (c) Tìm kiếm phần tử
struct node* find(struct node *head, int data) {
    struct node *current = head;
    while (current != NULL) {
        if (current->data == data) return current;
        current = current->next;
    }
    return NULL;
}

// (d) Xóa một node được chỉ định
struct node* delnode(struct node *head, struct node *pelement) {
    if (head == NULL || pelement == NULL) return head;

    // Trường hợp cần xóa là node head
    if (head == pelement) {
        struct node *temp = head->next;
        free(head);
        return temp;
    }

    struct node *current = head;
    while (current->next != NULL && current->next != pelement) {
        current = current->next;
    }

    // Nếu tìm thấy node nằm ngay trước pelement
    if (current->next == pelement) {
        current->next = pelement->next;
        free(pelement);
    }
    return head;
}

// (e) Giải phóng toàn bộ danh sách
void freelist(struct node *head) {
    struct node *current = head;
    struct node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    printf("List has been freed.\n");
}

// (f) Test code (Hàm main)
int main() {
    struct node *head = NULL;
    
    // Test (b) addback
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);
    
    // Test (a) display
    display(head);
    
    // Test (c) find
    struct node *target = find(head, 20);
    if (target != NULL) {
        printf("Found node with data: %d\n", target->data);
    } else {
        printf("Node not found!\n");
    }
    
    // Test (d) delnode
    printf("Deleting node with data 20...\n");
    head = delnode(head, target);
    display(head);
    
    printf("Deleting head node...\n");
    head = delnode(head, head);
    display(head);
    
    // Test (e) freelist
    freelist(head);
    head = NULL; // Tránh con trỏ lơ lửng
    
    return 0;
}