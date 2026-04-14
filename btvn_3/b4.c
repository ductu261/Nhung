/*******************************************************************************
 * Description  : Xem xét thuật toán sắp xếp chèn. (a) Cài đặt lại hàm 
 * shift_element() sử dụng con trỏ và phép toán con trỏ thay vì chỉ mục mảng. 
 * (b) Cài đặt lại hàm insertion_sort() chứa vòng lặp chính của thuật toán 
 * bằng con trỏ thay vì chỉ mục mảng.
 ******************************************************************************/
#include <stdio.h>

#define ARRAY_SIZE 5

// Biến toàn cục theo mô tả của đề bài
int arr[ARRAY_SIZE] = {5, 2, 4, 6, 1};
unsigned int len = ARRAY_SIZE;

// (a) Hàm dịch chuyển phần tử sử dụng con trỏ
void shift_element(int *pElement) 
{
    int ivalue = *pElement;
    int *pCurrent = pElement;

    // Dịch các phần tử lớn hơn ivalue lên một vị trí
    // pCurrent > arr đảm bảo không lùi quá đầu mảng
    while ((pCurrent > arr) && (*(pCurrent - 1) > ivalue)) 
    {
        *pCurrent = *(pCurrent - 1);
        pCurrent--;
    }
    
    // Đặt phần tử vào đúng vị trí
    *pCurrent = ivalue;
}

// (b) Hàm sắp xếp chèn sử dụng con trỏ
void insertion_sort(void) 
{
    int *pStart = arr;
    int *pEnd = arr + len;
    int *pCurrent;

    // Duyệt từ phần tử thứ hai đến cuối mảng
    for (pCurrent = pStart + 1; pCurrent < pEnd; pCurrent++) 
    {
        // Nếu phần tử hiện tại nhỏ hơn phần tử trước nó thì tiến hành chèn
        if (*pCurrent < *(pCurrent - 1)) 
        {
            shift_element(pCurrent);
        }
    }
}

int main(void) 
{
    int i;

    printf("Truoc khi sap xep: ");
    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion_sort();

    printf("Sau khi sap xep: ");
    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}