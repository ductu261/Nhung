#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Tree Node
struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
};

// (a) Cấp phát node mới
struct tnode* talloc(int data) {
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// (b) Thêm node vào cây Nhị Phân Tìm Kiếm (BST)
struct tnode* addnode(struct tnode *root, int data) {
    if (root == NULL) {
        return talloc(data);
    }
    
    if (data < root->data) {
        root->left = addnode(root->left, data);
    } else if (data > root->data) {
        root->right = addnode(root->right, data);
    }
    return root;
}

// (c) Duyệt tiền tự (N-L-R)
void preorder(struct tnode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// (d) Duyệt trung tự (L-N-R)
void inorder(struct tnode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// (e) Xóa cây (Sử dụng duyệt hậu tự - L-R-N)
int deltree(struct tnode *root) {
    if (root == NULL) return 0;
    
    int left_count = deltree(root->left);
    int right_count = deltree(root->right);
    
    free(root);
    return left_count + right_count + 1;
}

// (f) Test code (Hàm main)
int main() {
    struct tnode *root = NULL;
    
    // Các phần tử cần chèn: 3, 1, 0, 2, 8, 6, 5, 9
    int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
    int n = sizeof(values)/sizeof(values[0]);
    
    printf("Inserting nodes: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = addnode(root, values[i]);
    }
    printf("\n");
    
    // Test (c) Pre-order
    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");
    
    // Test (d) In-order
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");
    
    // Test (e) Deltree
    int deleted_count = deltree(root);
    root = NULL; // Tránh con trỏ lơ lửng
    printf("Tree deleted successfully. Number of nodes deleted: %d\n", deleted_count);
    
    return 0;
}