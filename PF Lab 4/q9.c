#include <stdio.h>
#include <stdbool.h>

int main()
{
  int height, age, canSwim, heartProblem;
  bool eligible = true;

  printf("Enter height (cm): ");
  scanf("%d", &height);
  printf("Enter age: ");
  scanf("%d", &age);
  printf("Can you swim? (1/0): ");
  scanf("%d", &canSwim);
  printf("Heart problems? (1/0): ");
  scanf("%d", &heartProblem);

  if (!(height >= 120 && height <= 200))
  {
    printf("Height not in range\n");
    eligible = false;
  }
  if (!(age >= 10))
  {
    printf("Age not in range\n");
    eligible = false;
  }
  if (!canSwim)
  {
    printf("You must be able to swim\n");
    eligible = false;
  }
  if (heartProblem)
  {
    printf("You must not have heart problems\n");
    eligible = false;
  }

  if (eligible)
  {
    printf("✓ Welcome to Thunder Wave! Enjoy your ride!\n");
  }
  else
  {
    printf("✗ Sorry, you are not eligible for the ride.\n");
  }

  return 0;
}