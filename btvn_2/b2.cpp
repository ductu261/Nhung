#include <iostream>

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

void itoa(int n, char s[]) {
    int i = 0, sign = n;

    do {
        int rem = n % 10;
        s[i++] = (rem < 0 ? -rem : rem) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);
}

int main() {
    char buffer[50];
    int min_int = 1 << 31; 
    
    itoa(min_int, buffer);
    std::cout << "Gia tri am lon nhat: " << min_int << '\n';
    std::cout << "Chuoi itoa: " << buffer << '\n';
    
    return 0;
}