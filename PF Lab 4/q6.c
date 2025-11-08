#include <stdio.h>

int main() {
    int dish, q;

    printf("===MENU===\n");
    printf("1. Pizza - $6\n");
    printf("2. Burger - $8\n");
    printf("3. Pasta - $10\n");
    printf("4. Salad - $6\n");
    printf("5. Soup - $5\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &dish);
    printf("Enter quantity: ");
    scanf("%d", &q);

    switch (dish)
    {
    case 1:
        printf("Your Order: %d Pizza(s)\n", q);
        printf("Total bill: %d", q * 6);
        break;
    case 2:
        printf("Your Order: %d Burger(s)\n", q);
        printf("Total bill: %d", q * 8);
        break;
    case 3:
        printf("Your Order: %d Pasta(s)\n", q);
        printf("Total bill: %d", q * 10);
        break;
    case 4:
        printf("Your Order: %d Salad(s)\n", q);
        printf("Total bill: %d", q * 6);
        break;
    case 5:
        printf("Your Order: %d Soup(s)\n", q);
        printf("Total bill: %d", q * 5);
        break;
    default:
    printf("Invalid choice!\n");
        break;
    }
}