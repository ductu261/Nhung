/*******************************************************************************
 * Description  : Trong bài toán này, chúng ta tiếp tục nghiên cứu về danh sách 
 * liên kết[cite: 114]. Giả sử các nút trong danh sách có cấu trúc struct node 
 * bao gồm data và next[cite: 115, 117, 119].
 * (a) Viết hàm void display(struct node *head) hiển thị tất cả các phần tử[cite: 121].
 * (b) Viết hàm struct node *addback(struct node *head, int data) thêm phần tử vào 
 * cuối danh sách và trả về head mới[cite: 122, 123].
 * (c) Viết hàm struct node *find(struct node *head, int data) trả về con trỏ đến 
 * phần tử, hoặc NULL nếu không tồn tại[cite: 124, 125].
 * (d) Viết hàm struct node *delnode(struct node *head, struct node *pelement) 
 * xóa phần tử và trả về head đã cập nhật[cite: 126, 127].
 * (e) Viết hàm void freelist(struct node *head) xóa tất cả phần tử[cite: 128].
 * (f) Viết mã kiểm thử minh họa hoạt động của từng hàm trên[cite: 130].
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

// (a) Hiển thị toàn bộ các phần tử trong danh sách
void display(struct node *head) 
{
    struct node *current = head;
    
    printf("Danh sach: ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// (b) Thêm một phần tử mới vào cuối danh sách liên kết
struct node *addback(struct node *head, int data) 
{
    // Cấp phát bộ nhớ cho nút mới
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;

    // Kiểm tra cấp phát thất bại
    if (new_node == NULL) 
    {
        printf("Loi: Khong the cap phat bo nho\n");
        return head; 
    }
    
    new_node->data = data;
    new_node->next = NULL;

    // Nếu danh sách đang trống, nút mới chính là head
    if (head == NULL) 
    {
        return new_node;
    }

    // Duyệt đến phần tử cuối cùng
    while (current->next != NULL) 
    {
        current = current->next;
    }
    
    // Nối nút mới vào cuối
    current->next = new_node;

    return head;
}

// (c) Tìm kiếm và trả về con trỏ tới nút chứa dữ liệu cần tìm
struct node *find(struct node *head, int data) 
{
    struct node *current = head;
    
    while (current != NULL) 
    {
        if (current->data == data) 
        {
            return current;
        }
        current = current->next;
    }
    
    return NULL; // Không tìm thấy
}

// (d) Xóa nút được chỉ định bởi con trỏ pelement
struct node *delnode(struct node *head, struct node *pelement) 
{
    struct node *current = head;
    struct node *prev = NULL;

    if (head == NULL || pelement == NULL) 
    {
        return head;
    }

    // Xử lý trường hợp đặc biệt: nút cần xóa chính là head
    if (head == pelement) 
    {
        head = head->next;
        free(pelement);
        return head;
    }

    // Tìm kiếm nút cần xóa và lưu lại nút ngay trước nó
    while (current != NULL && current != pelement) 
    {
        prev = current;
        current = current->next;
    }

    // Nếu tìm thấy, thực hiện gỡ nút và giải phóng bộ nhớ
    if (current != NULL) 
    {
        prev->next = current->next;
        free(current);
    }

    return head;
}

// (e) Xóa sạch toàn bộ danh sách và giải phóng bộ nhớ
void freelist(struct node *head) 
{
    struct node *current = head;
    struct node *next_node;

    while (current != NULL) 
    {
        next_node = current->next; // Lưu lại con trỏ nút tiếp theo
        free(current);             // Giải phóng nút hiện tại
        current = next_node;       // Chuyển sang nút tiếp theo
    }
}

// (f) Mã kiểm thử
int main(void) 
{
    struct node *head = NULL;
    struct node *target_node = NULL;

    // Thêm các phần tử vào danh sách
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);
    
    printf("Sau khi them phan tu:\n");
    display(head);

    // Tìm và xóa một phần tử ở giữa (ví dụ: 20)
    target_node = find(head, 20);
    if (target_node != NULL) 
    {
        printf("\nDa tim thay %d. Tien hanh xoa...\n", target_node->data);
        head = delnode(head, target_node);
    }
    display(head);

    // Tìm và xóa phần tử ở đầu (ví dụ: 10)
    target_node = find(head, 10);
    if (target_node != NULL) 
    {
        printf("\nDa tim thay %d (head). Tien hanh xoa...\n", target_node->data);
        head = delnode(head, target_node);
    }
    display(head);

    // Giải phóng toàn bộ danh sách
    freelist(head);
    head = NULL; // Đảm bảo không sử dụng lại con trỏ head
    printf("\nDa xoa toan bo danh sach.\n");

    return 0;
}