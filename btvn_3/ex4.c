#include <stdio.h>

void shift_element(int *arr, int *pElement)
{
    int value = *pElement;

    while (pElement > arr && *(pElement - 1) > value)
    {
        *pElement = *(pElement - 1);
        pElement--;
    }

    *pElement = value;
}

void insertion_sort(int *arr, int len)
{
    int *p;

    for (p = arr + 1; p < arr + len; p++)
    {
        if (*p < *(p - 1))
        {
            shift_element(arr, p);
        }
    }
}

int main()
{
    int arr[] = {8, 3, 5, 2, 9, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}