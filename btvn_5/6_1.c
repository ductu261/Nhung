/*******************************************************************************
 * Description  : Trong bài toán này, chúng ta sẽ sử dụng và tạo các hàm tận 
 * dụng con trỏ hàm. Một mảng các bản ghi gồm firstname, lastname và 
 * age của sinh viên.
 * - Sắp xếp các bản ghi theo firstname sử dụng qsort().
 * - Sắp xếp các bản ghi theo lastname sử dụng qsort().
 * - Hàm void apply(...) lặp qua các phần tử của mảng và gọi một hàm 
 * cho mỗi phần tử. Viết hàm isolder() in ra bản ghi nếu tuổi lớn 
 * hơn 20 và không làm gì nếu ngược lại.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char firstname[50];
    char lastname[50];
    int age;
};

// Hàm so sánh theo firstname dùng cho thuật toán qsort
int compare_firstname(const void *pa, const void *pb) 
{
    const struct student *s1 = (const struct student *)pa;
    const struct student *s2 = (const struct student *)pb;
    return strcmp(s1->firstname, s2->firstname);
}

// Hàm so sánh theo lastname dùng cho thuật toán qsort
int compare_lastname(const void *pa, const void *pb) 
{
    const struct student *s1 = (const struct student *)pa;
    const struct student *s2 = (const struct student *)pb;
    return strcmp(s1->lastname, s2->lastname);
}

// Hàm in bản ghi nếu tuổi lớn hơn 20
void isolder(struct student *s) 
{
    if (s->age > 20) 
    {
        printf("Ten: %s %s, Tuoi: %d\n", s->firstname, s->lastname, s->age);
    }
}

// Hàm áp dụng một con trỏ hàm lên từng phần tử của mảng
void apply(struct student *arr, int num, void (*fp)(struct student *)) 
{
    int i;
    for (i = 0; i < num; i++) 
    {
        fp(&arr[i]);
    }
}

int main(void) 
{
    int i;
    int num_students = 3;
    struct student class_list[] = {
        {"John", "Doe", 19},
        {"Alice", "Smith", 22},
        {"Bob", "Johnson", 25}
    };

    printf("--- Sap xep theo First Name ---\n");
    qsort(class_list, num_students, sizeof(struct student), compare_firstname);
    
    for (i = 0; i < num_students; i++) 
    {
        printf("%s %s, Tuoi: %d\n", class_list[i].firstname, class_list[i].lastname, class_list[i].age);
    }

    printf("\n--- Sap xep theo Last Name ---\n");
    qsort(class_list, num_students, sizeof(struct student), compare_lastname);
    
    for (i = 0; i < num_students; i++) 
    {
        printf("%s %s, Tuoi: %d\n", class_list[i].firstname, class_list[i].lastname, class_list[i].age);
    }

    printf("\n--- Sinh vien tren 20 tuoi (dung ham apply) ---\n");
    apply(class_list, num_students, isolder);

    return 0;
}