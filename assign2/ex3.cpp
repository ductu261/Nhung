#include <stdio.h>

void expand(char s1[], char s2[]) {
    int i, j;
    char c;

    j = 0; // Chỉ số cho mảng đích s2
    
    // Duyệt qua từng ký tự của s1 cho đến khi gặp ký tự kết thúc chuỗi '\0'
    for (i = 0; (c = s1[i]) != '\0'; i++) {
        
        // Kiểm tra xem c có phải là dấu gạch nối nằm ở GIỮA chuỗi không
        if (c == '-' && i > 0 && s1[i+1] != '\0') {
            char prev = s1[i-1];
            char next = s1[i+1];
            
            // Cờ đánh dấu tính hợp lệ của dải (0 là sai, 1 là đúng)
            int is_valid = 0;
            
            // Kiểm tra 3 trường hợp: dải chữ thường, dải chữ hoa, dải chữ số
            if (prev >= 'a' && prev <= 'z' && next >= 'a' && next <= 'z' && prev < next) {
                is_valid = 1;
            } else if (prev >= 'A' && prev <= 'Z' && next >= 'A' && next <= 'Z' && prev < next) {
                is_valid = 1;
            } else if (prev >= '0' && prev <= '9' && next >= '0' && next <= '9' && prev < next) {
                is_valid = 1;
            }

            // Nếu đây là một dải hợp lệ, ta tiến hành khai triển
            if (is_valid) {
                char k;
                // Chỉ điền các ký tự ở GIỮA prev và next
                // (Vì bản thân prev đã được in ở vòng lặp trước, 
                // và next sẽ được in ở vòng lặp sau)
                for (k = prev + 1; k < next; k++) {
                    s2[j++] = k;
                }
                
                // Lệnh continue giúp vòng lặp bỏ qua lệnh s2[j++] = c ở dưới, 
                // nghĩa là triệt tiêu dấu '-' này.
                continue; 
            }
        }
        
        // Chép các ký tự bình thường (kể cả dấu '-' ở đầu/cuối hoặc không hợp lệ) sang s2
        s2[j++] = c;
    }
    
    // Chốt đuôi chuỗi s2
    s2[j] = '\0';
}

int main() {
    char s1[] = "-a-z 0-9 a-b-c a-R-";
    char s2[100]; // Đảm bảo mảng đủ rộng để chứa chuỗi sau khi khai triển

    expand(s1, s2);
    
    printf("Chuoi goc:      %s\n", s1);
    printf("Chuoi mo rong:  %s\n", s2);

    return 0;
}