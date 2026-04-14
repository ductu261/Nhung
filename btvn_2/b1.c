/*******************************************************************************
 * Description  : Cả vòng lặp for và do-while đều có thể được chuyển đổi thành 
 * một vòng lặp while đơn giản. Đối với mỗi ví dụ sau, hãy viết mã 
 * tương đương bằng cách sử dụng vòng lặp while. Bạn chỉ cần sửa đổi 
 * hàm sample_geometric_rv().
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) 
{
    int i = 2;
    int ret = 1;
    
    // Lặp trong khi i nhỏ hơn hoặc bằng n
    while (i <= n) 
    {
        ret *= i;
        i++;
    }
    
    return ret;
}

double rand_double(void) 
{
    // Tạo số ngẫu nhiên trong khoảng (0,1)
    double ret = (double) rand();
    return ret / (RAND_MAX + 1);
}

int sample_geometric_rv(double p) 
{
    double q;
    int n = 0;
    
    // Thực hiện lần đầu tiên giống như do-while
    q = rand_double();
    n++;
    
    // Lặp trong khi q lớn hơn hoặc bằng p
    while (q >= p) 
    {
        q = rand_double();
        n++;
    }
    
    return n;
}

int main(void)
{
    int n = 5;
    double p = 0.5;

    printf("Giai thua cua %d la: %d\n", n, factorial(n));
    printf("Mau phan phoi hinh hoc (p = %.2f): %d\n", p, sample_geometric_rv(p));

    return 0;
}