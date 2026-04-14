/*******************************************************************************
 * Description  : Trong bài toán này, chúng ta tiếp tục nghiên cứu về cây nhị phân[cite: 132, 133]. 
 * Giả sử các nút có cấu trúc struct tnode gồm data, left và right[cite: 134, 137, 138, 139].
 * (a) Viết hàm struct tnode *talloc(int data) cấp phát một nút mới[cite: 141].
 * (b) Hoàn thành hàm addnode() để chèn các phần tử 3, 1, 0, 2, 8, 6, 5, 9 
 * theo đúng thứ tự[cite: 142, 143].
 * (c) Viết hàm void preorder(struct tnode *root) hiển thị bằng duyệt tiền thứ tự[cite: 144].
 * (d) Viết hàm void inorder(struct tnode *root) hiển thị bằng duyệt trung thứ tự[cite: 145].
 * (e) Viết hàm int deltree(struct tnode *root) xóa tất cả phần tử và trả về số 
 * lượng nút đã xóa (Gợi ý: dùng duyệt hậu thứ tự)[cite: 146, 147, 148].
 * (f) Viết mã kiểm thử minh họa hoạt động của từng hàm trên[cite: 149].
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct tnode 
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

// (a) Cấp phát một nút mới trên cây
struct tnode *talloc(int data) 
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
    
    if (new_node != NULL) 
    {
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    
    return new_node;
}

// (b) Chèn phần tử vào cây tìm kiếm nhị phân
struct tnode *addnode(struct tnode *root, int data) 
{
    // Cây rỗng, tạo nút gốc
    if (root == NULL) 
    {
        return talloc(data);
    }
    
    // Đưa dữ liệu nhỏ hơn sang nhánh trái
    if (data < root->data) 
    {
        root->left = addnode(root->left, data);
    } 
    // Đưa dữ liệu lớn hơn sang nhánh phải
    else if (data > root->data) 
    {
        root->right = addnode(root->right, data);
    }
    
    // Nếu bằng nhau thì bỏ qua (cây không chứa giá trị trùng)
    return root;
}

// (c) Duyệt và hiển thị cây theo tiền thứ tự (Pre-order: Node-Left-Right)
void preorder(struct tnode *root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// (d) Duyệt và hiển thị cây theo trung thứ tự (In-order: Left-Node-Right)
void inorder(struct tnode *root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// (e) Xóa cây bằng cách duyệt hậu thứ tự (Post-order: Left-Right-Node)
int deltree(struct tnode *root) 
{
    int count = 0;
    
    if (root != NULL) 
    {
        // Xóa nhánh trái trước, rồi xóa nhánh phải
        count += deltree(root->left);
        count += deltree(root->right);
        
        // Giải phóng nút hiện tại
        free(root);
        count += 1; // Tăng bộ đếm khi một nút bị xóa
    }
    
    return count;
}

// (f) Mã kiểm thử
int main(void) 
{
    struct tnode *root = NULL;
    int deleted_nodes = 0;

    // Chèn các phần tử theo thứ tự: 3, 1, 0, 2, 8, 6, 5, 9
    root = addnode(root, 3);
    root = addnode(root, 1);
    root = addnode(root, 0);
    root = addnode(root, 2);
    root = addnode(root, 8);
    root = addnode(root, 6);
    root = addnode(root, 5);
    root = addnode(root, 9);

    printf("Duyet tien thu tu (Pre-order): ");
    preorder(root);
    printf("\n");

    printf("Duyet trung thu tu (In-order - da sap xep): ");
    inorder(root);
    printf("\n");

    // Xóa toàn bộ cây và đếm số lượng nút
    deleted_nodes = deltree(root);
    root = NULL; // Không sử dụng con trỏ sau khi đã giải phóng
    
    printf("Da xoa cay. Tong so nut bi xoa: %d\n", deleted_nodes);

    return 0;
}