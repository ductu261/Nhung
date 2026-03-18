#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// sinh số random trong khoảng [0,1]
double rand_double() {
    return (double)rand() / RAND_MAX;
}

// hàm tính giai thừa
int factorial(int n) {
    int i, ret = 1;

    i = 2;
    while (i <= n) {
        ret *= i;
        i++;
    }

    return ret;
}

// mô phỏng biến ngẫu nhiên hình học
int sample_geometric_rv(double p) {
    double q;
    int n = 0;

    q = rand_double();
    n++;

    while (q >= p) {
        q = rand_double();
        n++;
    }

    return n;
}

int main() {

    srand(time(NULL));

    printf("5! = %d\n", factorial(5));

    double p = 0.3;

    for(int i=0;i<10;i++){
        printf("Geometric sample: %d\n", sample_geometric_rv(p));
    }

    return 0;
}