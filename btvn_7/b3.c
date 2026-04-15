/*******************************************************************************
 * Description  : Mô phỏng hệ thống hàng đợi khám bệnh tại bệnh viện bằng cấu 
 * trúc Max-Heap trên mảng. Bệnh nhân có mức ưu tiên cao hơn sẽ được khám trước.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

// Cấu trúc bệnh nhân
struct Patient 
{
    char name[50];
    int priority;
};

// Mảng biểu diễn Max-Heap
struct Patient heap[MAX_PATIENTS];
int heap_size = 0;

// Hàm hỗ trợ đổi chỗ 2 bệnh nhân
void swap(struct Patient *a, struct Patient *b) 
{
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Thực hiện heapify-up khi thêm vào hàng đợi
void heapify_up(int index) 
{
    int parent = (index - 1) / 2;
    
    // Nếu nút hiện tại có ưu tiên lớn hơn nút cha, tiến hành đổi chỗ
    if (index > 0 && heap[index].priority > heap[parent].priority) 
    {
        swap(&heap[index], &heap[parent]);
        heapify_up(parent); // Gọi đệ quy lên trên
    }
}

// Thực hiện heapify-down khi lấy ra khỏi hàng đợi
void heapify_down(int index) 
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // So sánh với con trái
    if (left < heap_size && heap[left].priority > heap[largest].priority) 
    {
        largest = left;
    }
    // So sánh với con phải
    if (right < heap_size && heap[right].priority > heap[largest].priority) 
    {
        largest = right;
    }

    // Nếu nút lớn nhất không phải là nút hiện tại, đổi chỗ và tiếp tục
    if (largest != index) 
    {
        swap(&heap[index], &heap[largest]);
        heapify_down(largest); // Gọi đệ quy xuống dưới
    }
}

// Hàm push: Thêm bệnh nhân
void push(struct Patient p) 
{
    if (heap_size >= MAX_PATIENTS) 
    {
        printf("Hang doi da day!\n");
        return;
    }
    
    // Thêm vào cuối mảng và vun đống lên
    heap[heap_size] = p;
    heapify_up(heap_size);
    heap_size++;
    
    printf("Da them: %s (Uu tien: %d)\n", p.name, p.priority);
}

// Hàm peek: Xem bệnh nhân ưu tiên cao nhất
void peek(void) 
{
    if (heap_size > 0) 
    {
        printf(">> Dang dung dau: %s (Uu tien: %d)\n", heap[0].name, heap[0].priority);
    } 
    else 
    {
        printf("Hang doi trong.\n");
    }
}

// Hàm pop: Lấy bệnh nhân ưu tiên cao nhất ra khám
struct Patient pop(void) 
{
    struct Patient top_patient = heap[0];
    
    if (heap_size <= 0) 
    {
        printf("Hang doi trong!\n");
        // Trả về bệnh nhân ảo nếu mảng trống
        struct Patient empty = {"", -1};
        return empty;
    }

    // Đưa phần tử cuối mảng lên làm gốc
    heap[0] = heap[heap_size - 1];
    heap_size--;
    
    // Vun đống xuống để tái tạo Max-Heap
    heapify_down(0);

    return top_patient;
}

int main(void) 
{
    struct Patient p;
    
    printf("--- Tiep nhan benh nhan ---\n");
    
    // Nhập 5 bệnh nhân với ưu tiên khác nhau
    p.priority = 2; strcpy(p.name, "Nguyen Van A"); push(p); peek();
    p.priority = 5; strcpy(p.name, "Tran Thi B");   push(p); peek();
    p.priority = 1; strcpy(p.name, "Le Van C");     push(p); peek();
    p.priority = 8; strcpy(p.name, "Pham Thi D");   push(p); peek();
    p.priority = 3; strcpy(p.name, "Hoang Van E");  push(p); peek();

    printf("\n--- Thu tu goi kham (Uu tien cao -> thap) ---\n");
    
    // Rút lần lượt bệnh nhân ra cho đến khi hàng đợi trống
    while (heap_size > 0) 
    {
        p = pop();
        printf("Goi kham: %s (Uu tien: %d)\n", p.name, p.priority);
    }

    return 0;
}