#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudent(int id, Student students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; ++i) {
        if (students[i].id == id) {
            for (int j = i; j < *currentLength - 1; ++j) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            found = 1;
            printf("Sinh vien co id %d da bi xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co id %d.\n", id);
    }
}

void printStudents(const Student students[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    for (int i = 0; i < currentLength; ++i) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
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
    int currentLength = 5;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);

    int idToDelete;
    printf("Nhap id sinh vien muon xoa: ");
    scanf("%d", &idToDelete);

    deleteStudent(idToDelete, students, &currentLength);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printStudents(students, currentLength);

    return 0;
}
