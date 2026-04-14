/*******************************************************************************
 * Description  : Viết chương trình expr đánh giá biểu thức ký pháp Ba Lan ngược 
 * từ command line, nơi mỗi toán tử hoặc toán hạng là một đối số riêng 
 * biệt. Ví dụ: expr 2 3 4 + * tính 2 * (3 + 4)[cite: 182, 183, 184, 185].
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 100

int stack[MAX_STACK];
int sp = 0; // Con trỏ ngăn xếp

void push(int val) 
{
    if (sp < MAX_STACK) 
    {
        stack[sp++] = val;
    } 
    else 
    {
        printf("Loi: Ngan xep da day\n");
    }
}

int pop(void) 
{
    if (sp > 0) 
    {
        return stack[--sp];
    } 
    printf("Loi: Ngan xep dang trong\n");
    return 0;
}

int main(int argc, char *argv[]) 
{
    int i;
    int op2;

    // Lặp qua các đối số truyền vào từ dòng lệnh (bỏ qua argv[0])
    for (i = 1; i < argc; i++) 
    {
        // Kiểm tra xem đối số là toán tử hay toán hạng
        if (argv[i][0] == '+' && argv[i][1] == '\0') 
        {
            push(pop() + pop());
        } 
        else if (argv[i][0] == '*' && argv[i][1] == '\0') 
        {
            push(pop() * pop());
        } 
        else if (argv[i][0] == '-' && argv[i][1] == '\0') 
        {
            op2 = pop();
            push(pop() - op2);
        } 
        else if (argv[i][0] == '/' && argv[i][1] == '\0') 
        {
            op2 = pop();
            if (op2 != 0) 
            {
                push(pop() / op2);
            } 
            else 
            {
                printf("Loi: Chia cho 0\n");
            }
        } 
        else 
        {
            // Nếu là số, chuyển từ chuỗi sang số nguyên và đẩy vào ngăn xếp
            push(atoi(argv[i]));
        }
    }

    // In kết quả cuối cùng nằm ở đỉnh ngăn xếp
    if (sp > 0) 
    {
        printf("Ket qua: %d\n", pop());
    }

    return 0;
}