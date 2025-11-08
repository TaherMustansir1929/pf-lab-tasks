#include <stdio.h>
#include <math.h>

int main()
{
  int choice;
  int a, b;

  printf("=====CALCULATOR=====\n");
  printf("Main Menu: 1-Basic, 2-Advance\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    choice = 0;
    printf("Basic Operations: 1-Addition, 2-Subtraction, 3-Multiplication, 4-Division\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    switch (choice)
    {
    case 1:
      printf("Result: %d + %d = %d\n", a, b, a + b);
      break;
    case 2:
      printf("Result: %d - %d = %d\n", a, b, a - b);
      break;
    case 3:
      printf("Result: %d * %d = %d\n", a, b, a * b);
      break;
    case 4:
      if (b == 0)
      {
        printf("Error: Division by Zero not allowed!\n");
        break;
      }
      printf("Result: %d / %d = %d\n", a, b, a / b);
      break;

    default:
      printf("Invalid Choice!\n");
      break;
    }
    break;
  case 2:
    choice = 0;
    printf("Advance Operations: 1-Power, 2-Modulus, 3-Absolute Difference\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch (choice)
    {
    case 1:
      printf("Result: %d ^ %d = %d\n", a, b, (int)pow((double)a, (double)b));
      break;
    case 2:
      printf("Result: %d %% %d = %d\n", a, b, a % b);
      break;
    case 3:
      printf("Result: |%d - %d| = %d\n", a, b, abs(a - b));
      break;

    default:
      printf("Invalid Choice!\n");
      break;
    }

    break;

  default:
    printf("Invalid Choice!\n");
    break;
  }
}