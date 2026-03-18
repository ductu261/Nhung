#include <stdio.h>

#define MAXVAL 100 // Kích thước tối đa của ngăn xếp

int sp = 0;          // Con trỏ ngăn xếp (Stack Pointer)
double val[MAXVAL];  // Mảng chứa các phần tử của ngăn xếp

// Các hàm gốc có sẵn từ sách K&R
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Loi: Ngan xep da day!\n");
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Loi: Ngan xep rong!\n");
        return 0.0;
    }
}

// ==========================================
// CÁC HÀM BỔ SUNG THEO YÊU CẦU BÀI 4-4
// ==========================================

// 1. In phần tử trên đỉnh mà không Pop (Peek)
void print_top(void) {
    if (sp > 0) {
        // sp luôn trỏ vào ô TRỐNG tiếp theo, 
        // nên phần tử thực sự nằm trên đỉnh có vị trí là (sp - 1)
        printf("\tPhan tu tren dinh: %g\n", val[sp - 1]);
    } else {
        printf("Loi: Ngan xep rong, khong co gi de in.\n");
    }
}

// 2. Nhân bản phần tử trên đỉnh (Duplicate)
void duplicate(void) {
    double temp;
    if (sp > 0) {
        temp = val[sp - 1]; // Đọc giá trị trên đỉnh (không pop)
        push(temp);         // Push chính giá trị đó vào lại ngăn xếp
    } else {
        printf("Loi: Ngan xep rong, khong the nhan ban.\n");
    }
}

// 3. Hoán đổi hai phần tử trên cùng (Swap)
void swap_top_two(void) {
    double temp1, temp2;
    if (sp > 1) {           // Phải có ít nhất 2 phần tử mới hoán đổi được
        temp1 = pop();      // Rút phần tử trên cùng ra
        temp2 = pop();      // Rút phần tử thứ hai ra
        
        push(temp1);        // Đẩy phần tử thứ nhất vào lại (nó sẽ nằm dưới)
        push(temp2);        // Đẩy phần tử thứ hai vào lại (nó sẽ ngoi lên trên)
    } else {
        printf("Loi: Ngan xep khong du 2 phan tu de hoan doi.\n");
    }
}

// 4. Xóa toàn bộ ngăn xếp (Clear)
void clear_stack(void) {
    sp = 0; 
}

int main() {

    printf("=== Test push ===\n");
    push(10);
    push(20);
    push(30);

    print_top();   // mong đợi: 30

    printf("\n=== Test duplicate ===\n");
    duplicate();   // nhân bản 30
    print_top();   // mong đợi: 30

    printf("\n=== Test swap ===\n");
    swap_top_two(); 
    print_top();   // mong đợi: 30 (vì swap 30 và 30)

    printf("\n=== Test pop ===\n");
    printf("Pop: %g\n", pop()); // lấy phần tử trên cùng
    print_top();               // xem phần tử mới

    printf("\n=== Test clear ===\n");
    clear_stack();
    print_top(); // sẽ báo stack rỗng

    return 0;
}