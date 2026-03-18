#include <iostream>

// Bắt buộc khai báo lại hàm reverse
void reverse(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i = 0, sign = n;

    do {
        int rem = n % b;
        int digit = (rem < 0 ? -rem : rem);
        
        if (digit <= 9) {
            s[i++] = digit + '0';
        } else {
            s[i++] = digit - 10 + 'A';
        }
    } while ((n /= b) != 0);

    if (sign < 0 && b == 10) {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);
}

int main() {
    char buffer[50];
    
    itob(255, buffer, 16);
    std::cout << "255 he 16: " << buffer << '\n';
    
    itob(-128, buffer, 10);
    std::cout << "-128 he 10: " << buffer << '\n';
    
    return 0;
}