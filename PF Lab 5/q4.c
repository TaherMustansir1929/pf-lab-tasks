#include <stdio.h>

int main()
{
  int year, feb_days = 28;
  char *result = "Not a leap year :(";

  printf("Enter year: ");
  scanf("%d", &year);

  if (year % 4 == 0)
  {
    printf("%d is divisible by 4\n", year);

    if (year % 100 == 0)
    {
      if (year % 400 == 0)
      {

        printf("%d is divisible by 100 and 400\n", year);
        result = "LEAP YEAR!";
        feb_days = 29;
      }
      else
      {
        printf("%d is divisible by 100 but not by 400\n", year);
      }
    }
    else
    {
      printf("%d is not divisible by 100\n", year);
      result = "LEAP YEAR!";
      feb_days = 29;
    }
  }
  else
  {
    printf("%d is not divisible by 4\n", year);
  }

  printf("Result: %s\n", result);
  printf("February has %d days in %d\n", feb_days, year);
}