#include <stdio.h>

int main() {
    int x, y;
    char op;

    printf("Enter an expression: ");
    scanf("%d %c %d", &x, &op, &y);

    switch (op)
    {
    case '+':
        printf("Result = %d\n", x + y);
        break;
    case '-':
        printf("Result = %d\n", x - y);
        break;
    case '*':
        printf("Result = %d\n", x * y);
        break;
    case '/':
        if (y == 0) {
            printf("Division by zero is not allowed!\n");
            break;
        }
        printf("Result = %d\n", x / y);
        break;
    
    default:
        printf("Invalid operator!\n");
        break;
    }
}