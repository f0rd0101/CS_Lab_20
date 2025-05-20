#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100


struct Student {
    char surname[50];
    char name[50];
    char group[20];
    float scholarship;
};


void printStudents(struct Student *students, int count) {
    printf("\n%-15s %-15s %-10s %-10s\n", "Прізвище", "Ім'я", "Група", "Стипендія");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-15s %-10s %.2f грн\n",
               students[i].surname,
               students[i].name,
               students[i].group,
               students[i].scholarship);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count;

    printf("Введіть кількість студентів: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("\nСтудент #%d:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", students[i].surname);
        printf("Ім'я: ");
        scanf("%s", students[i].name);
        printf("Група: ");
        scanf("%s", students[i].group);
        printf("Стипендія (грн): ");
        scanf("%f", &students[i].scholarship);
    }

    char targetSurname[50];
    float newScholarship;

    printf("\nВведіть прізвище студента для зміни стипендії: ");
    scanf("%s", targetSurname);
    printf("Введіть нову стипендію (грн): ");
    scanf("%f", &newScholarship);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].surname, targetSurname) == 0) {
            students[i].scholarship = newScholarship;
            found = 1;
        }
    }

    if (!found) {
        printf("Студента з таким прізвищем не знайдено.\n");
    }

    printStudents(students, count);

    return 0;
}
