// chuyen vong lap for thanh while 
#include <iostream>

int factorial(int n) {
    int i = 2, ret = 1;
    
    while (i <= n) {
        ret *= i;
        i++;
    }
    
    return ret;
}

int main() {
    int n = 5;
    std::cout << "Giai thua cua " << n << " la: " << factorial(n) << std::endl;
    return 0;
}