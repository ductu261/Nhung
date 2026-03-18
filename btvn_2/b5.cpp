#include <iostream>

#define MAXVAL 100

int sp = 0;            
double val[MAXVAL];    

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        std::cout << "Loi: Ngan xep da day.\n";
    }
}

void print_top() {
    if (sp > 0)
        std::cout << "Dinh ngan xep: " << val[sp - 1] << '\n';
    else
        std::cout << "Loi: Ngan xep dang trong.\n";
}

void duplicate_top() {
    if (sp > 0 && sp < MAXVAL) {
        val[sp] = val[sp - 1]; 
        sp++;                  
        std::cout << "Da nhan ban.\n";
    } else {
        std::cout << "Loi: Ngan xep trong hoac da day.\n";
    }
}

void swap_top() {
    if (sp > 1) {
        // Tự hoán đổi không dùng std::swap
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
        std::cout << "Da hoan doi.\n";
    } else {
        std::cout << "Loi: Can it nhat 2 phan tu.\n";
    }
}

void clear_stack() {
    sp = 0;
    std::cout << "Da xoa ngan xep.\n";
}

int main() {
    push(10.5);
    push(25.0);
    
    std::cout << "--- Truoc khi hoan doi ---\n";
    print_top(); 
    
    std::cout << "\n--- Thuc hien Swap ---\n";
    swap_top();
    print_top(); 
    
    return 0;
}