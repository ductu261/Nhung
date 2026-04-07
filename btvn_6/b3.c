#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100

int sp = 0;          // Vị trí đỉnh ngăn xếp
double val[MAXVAL];  // Mảng chứa giá trị ngăn xếp

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Loi: Ngan xep day, khong the push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Loi: Ngan xep trong\n");
        return 0.0;
    }
}

int main(int argc, char *argv[]) {
    double op2;

    // Bỏ qua tên chương trình (argv[0]), bắt đầu từ argv[1]
    while (--argc > 0) {
        argv++;
        char *s = *argv;

        // Nếu là số (bao gồm cả số âm)
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))) {
            push(atof(s));
        } else {
            // Nếu là toán tử
            switch (s[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop(); // Phải pop số thứ 2 ra trước
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("Loi: Chia cho 0\n");
                    break;
                default:
                    printf("Loi: Khong nhan dien duoc lenh %s\n", s);
                    break;
            }
        }
    }
    
    // In kết quả cuối cùng trên ngăn xếp
    printf("%.8g\n", pop());
    return 0;
}