#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudentsByName(Student students[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                swap(&students[i], &students[j]);
            }
        }
    }
}

void printStudents(const Student students[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[5] = {
        {1, "Nguyen A", 20, "0912345678"},
        {2, "Tran B", 21, "0923456789"},
        {3, "Le C", 22, "0934567890"},
        {4, "Pham D", 23, "0945678901"},
        {5, "Hoang E", 24, "0956789012"}
    };
    int length = 5;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, length);

    sortStudentsByName(students, length);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, length);

    return 0;
}
