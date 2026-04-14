/*******************************************************************************
 * Description  : Thêm các lệnh để in phần tử trên cùng của ngăn xếp mà không lấy 
 * ra, nhân bản nó, và hoán đổi hai phần tử trên cùng. Thêm một lệnh 
 * để xóa ngăn xếp.
 ******************************************************************************/
#include <stdio.h>

#define MAX_VAL 100

int sp = 0;            // Con trỏ chỉ mục đỉnh ngăn xếp
double val[MAX_VAL];   // Mảng lưu trữ các giá trị của ngăn xếp

void push(double f) 
{
    if (sp < MAX_VAL) 
    {
        val[sp++] = f;
    } 
    else 
    {
        printf("Loi: Ngan xep da day\n");
    }
}

double pop(void) 
{
    if (sp > 0) 
    {
        return val[--sp];
    } 
    printf("Loi: Ngan xep dang trong\n");
    return 0.0;
}

// Lệnh in phần tử trên cùng
void print_top(void) 
{
    if (sp > 0) 
    {
        printf("Phan tu tren cung: %g\n", val[sp - 1]);
    } 
    else 
    {
        printf("Ngan xep dang trong\n");
    }
}

// Lệnh nhân bản phần tử trên cùng
void duplicate_top(void) 
{
    if (sp > 0)
    {
        double temp = pop();
        push(temp);
        push(temp);
    }
}

// Lệnh hoán đổi hai phần tử trên cùng
void swap_top_two(void) 
{
    if (sp > 1) 
    {
        double temp1 = pop();
        double temp2 = pop();
        
        // Đẩy vào theo thứ tự đảo ngược
        push(temp1);
        push(temp2);
    } 
    else
    {
        printf("Loi: Khong du phan tu de hoan doi\n");
    }
}

// Lệnh xóa sạch ngăn xếp
void clear_stack(void) 
{
    sp = 0;
    printf("Da xoa ngan xep\n");
}

int main(void)
{
    push(1.5);
    push(3.0);
    
    print_top();       // In ra 3.0
    
    duplicate_top();   
    print_top();       // Vẫn in ra 3.0 (bản sao)
    
    swap_top_two();    // Hoán đổi 3.0 và 3.0
    
    pop();             // Lấy bản sao ra
    pop();             // Lấy bản gốc ra
    print_top();       // In ra 1.5
    
    clear_stack();
    print_top();       // Báo ngăn xếp trống

    return 0;
}