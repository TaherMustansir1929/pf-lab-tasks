#include <stdio.h>

int main() {
    int s1, s2;
    printf("Sensor 1 (1/0): ");
    scanf("%d", &s1);
    printf("Sensor 2 (1/0): ");
    scanf("%d", &s2);

    if (s1 == 1) {
        if (s2 == 1) {
            printf("Green Light - 30 seconds\n");
        } else if (s2 == 0) {
            printf("Red Light - stay\n");
        }
    } else {
        if (s2 == 0) {
            printf("Red Light - Stay\n");
        } else {
            printf("Green Light - 45 seconds\n");
        }
    }
}