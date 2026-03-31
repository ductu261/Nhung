#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Record dựa trên mô tả
typedef struct {
    char firstname[50];
    char lastname[50];
    int age;
} Record;

// 1. Hàm callback để so sánh theo First Name
int compare_firstname(const void* pa, const void* pb) {
    const Record* a = (const Record*)pa;
    const Record* b = (const Record*)pb;
    return strcmp(a->firstname, b->firstname);
}

// 2. Hàm callback để so sánh theo Last Name
int compare_lastname(const void* pa, const void* pb) {
    const Record* a = (const Record*)pa;
    const Record* b = (const Record*)pb;
    return strcmp(a->lastname, b->lastname);
}

// 3. Hàm isolder: In ra nếu tuổi > 20
void isolder(void* ptr) {
    Record* r = (Record*)ptr;
    if (r->age > 20) {
        printf("Name: %s %s, Age: %d\n", r->firstname, r->lastname, r->age);
    }
}

// Hàm apply: Lặp qua mảng và gọi hàm callback cho từng phần tử
void apply(Record* arr, int num, void (*fn)(void*)) {
    for (int i = 0; i < num; i++) {
        fn(&arr[i]);
    }
}

int main() {
    Record students[] = {
        {"John", "Doe", 19},
        {"Alice", "Smith", 22},
        {"Bob", "Johnson", 25}
    };
    int num_students = sizeof(students) / sizeof(students[0]);

    // Sắp xếp theo firstname
    qsort(students, num_students, sizeof(Record), compare_firstname);
    
    // Gọi hàm apply để in các sinh viên > 20 tuổi
    printf("Students older than 20:\n");
    apply(students, num_students, isolder);

    return 0;
}