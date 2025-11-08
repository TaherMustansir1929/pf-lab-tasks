#include <stdio.h>

int main() {
    int day, age;
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter age (1-7): ");
    scanf("%d", &day);

    if (age < 12 && age >0) {
        printf("Children ticket ");
        day == 3 ? (printf("with Wednesday dicount: $%d\n", 5 / 2)) : (printf(": 5\n"));
    } else if (age <= 22 && age >= 12) {
        printf("Student ticket ");
        day == 3 ? (printf("with Wednesday dicount: $%d\n", 8 / 2)) : (printf(": 8\n"));
    } else if (age > 22) {
        printf("Adult ticket ");
        day == 3 ? (printf("with Wednesday dicount: $%d\n", 12 / 2)) : (printf(": 12\n"));
    } else {
        printf("Invalid input");
    }
}