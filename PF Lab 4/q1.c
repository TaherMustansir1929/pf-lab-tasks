#include <stdio.h>

int main() {
    int w=0;
    printf("Enter current weight in elevator: ");
    scanf("%d", &w);

    if (w>500) {
        printf("OVERLOAD! Please exit the elevator.");
    } else {
        printf("Its safe to go!");
    }
}