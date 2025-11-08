#include <stdio.h>
#include <math.h>

int main()
{
  int a, b, c;
  char *type;

  printf("Enter 3 sides: ");
  scanf("%d %d %d", &a, &b, &c);

  if ((a + b) > c && (a + c) > b && (b + c) > a)
  {
    printf("Valid triangle!\n");
    if (a == b && a == c)
    {
      type = "Equilateral";
    }
    else if (a == b || a == c || b == c)
    {
      type = "Isosceles";
    }
    else if (a != b && a != c && b != c)
    {
      type = "Scalene";
    }

    double perimeter, area, s;

    perimeter = a + b + c;
    s = perimeter / 2;
    area = sqrt((s * (s - a) * (s - b) * (s - c)));

    printf("Type: %s triangle\n", type);
    printf("Perimeter: %.0lf\n", perimeter);
    printf("Area: %.0lf\n", area);

    if (pow(c, 2) == pow(a, 2) + pow(b, 2))
    {
      printf("\nSpecial: This is a RIGHT TRIANGLE\n");
    }
    else
    {
      printf("\nSpecial: This is NOT a RIGHT TRIANGLE\n");
    }
  }
  else
  {
    printf("Invalid triangle!");
  }
}