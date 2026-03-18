#include <iostream>

void expand(char s1[], char s2[]) {
    int i = 0, j = 0, c;

    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++; // Bỏ qua dấu '-'
            while (c < s1[i]) {
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "-a-c0-5"; 
    char s2[200]; 
    
    expand(s1, s2);
    
    std::cout << "Chuoi goc: " << s1 << '\n';
    std::cout << "Chuoi mo rong: " << s2 << '\n';
    
    return 0;
}