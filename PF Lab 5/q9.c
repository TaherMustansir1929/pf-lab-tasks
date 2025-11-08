#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  double a, b, c;

  printf("Enter coefficients: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  if (a == 0)
  {
    printf("Not a quadratic equation!\n");
    exit(1);
  }

  printf("Equation: %.2lfx^2 %s %.2lfx %s %.2lf\n",
         a,
         b < 0 ? "-" : "+", fabs(b),
         c < 0 ? "-" : "+", fabs(c));

  double discriminant = b * b - 4 * a * c;
  printf("Discriminant: %.2lf\n", discriminant);

  if (discriminant > 0)
  {
    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("Nature: Two distinct real roots\n");
    printf("Root1: %.2lf\nRoot2: %.2lf\n", root1, root2);
  }
  else if (discriminant == 0)
  {
    double root = -b / (2 * a);
    printf("Nature: One real root\n");
    printf("Root: %.2lf\n", root);
  }
  else
  {
    double realPart = -b / (2 * a);
    double imaginaryPart = sqrt(-discriminant) / (2 * a);
    printf("Nature: Two complex roots\n");
    printf("Root1: %.2lf + %.2lfi\n", realPart, imaginaryPart);
    printf("Root2: %.2lf - %.2lfi\n", realPart, imaginaryPart);
  }

  return 0;
}
