#include <stdio.h>
#include <limits.h>

int main() {
    printf("--- Sử dụng thư viện <limits.h> ---\n");
    printf("Signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 to %u\n", USHRT_MAX);
    printf("Signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0 to %u\n", UINT_MAX);
    printf("Signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 to %lu\n\n", ULONG_MAX);

    printf("--- Bằng cách tính toán trực tiếp (Bitwise) ---\n");
    // Tính toán bằng cách tận dụng biểu diễn nhị phân bù 2
    printf("Signed char: %d to %d\n", -(char)((unsigned char)~0 >> 1) - 1, (char)((unsigned char)~0 >> 1));
    printf("Unsigned char: 0 to %u\n", (unsigned char)~0);
    
    printf("Signed short: %d to %d\n", -(short)((unsigned short)~0 >> 1) - 1, (short)((unsigned short)~0 >> 1));
    printf("Unsigned short: 0 to %u\n", (unsigned short)~0);
    
    printf("Signed int: %d to %d\n", -(int)((unsigned int)~0 >> 1) - 1, (int)((unsigned int)~0 >> 1));
    printf("Unsigned int: 0 to %u\n", (unsigned int)~0);
    
    printf("Signed long: %ld to %ld\n", -(long)((unsigned long)~0 >> 1) - 1, (long)((unsigned long)~0 >> 1));
    printf("Unsigned long: 0 to %lu\n", (unsigned long)~0);

    return 0;
}