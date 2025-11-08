#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  char *sign, *property, *special;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (n == 0)
  {
    sign = "Zero";
    property = "Number is zero";
  }
  else if (n > 0)
  {
    sign = "Positive";
    if (n % 2 == 0)
    {
      property = "Even number";
    }
    else
    {
      property = "Odd number";
    }

    int root = (int)sqrt(n);
    if (root * root == n)
    {
      special = "Number is a perfect square";
    }
    else
    {
      special = "Not a perfect square";
    }
  }
  else
  {
    sign = "Negative";
    if (n % 3 == 0)
    {
      property = "Divisible by 3";
    }
    else
    {
      property = "Not divisible by 3";
    }
  }

  printf("Number is: %s\n", sign);
  printf("Property: %s\n", property);
  printf("Special: %s\n", special);
}