#include <stdio.h>
#include <math.h>

int main()
{
  int n;

  printf("Enter a positive number: ");
  scanf("%d", &n);

  int digit = 0, temp = n;
  do
  {
    digit++;
    temp /= 10;
  } while (temp > 0);
  printf("Digit count: %d\n", digit);

  int root = sqrt(n);
  if (root * root == n)
  {
    printf("Perfect square: Yes (%d x %d)\n", root, root);
  }
  else
  {
    printf("Perfect square: No\n");
  }

  if ((n > 0 && n & (n - 1)) == 0)
  {
    int exp = 0, p = n;
    while (p > 1)
    {
      exp++;
      p = p >> 1;
    }

    printf("Power of 2: Yes (2^%d)\n", exp);
  }
  else
  {
    printf("Power of 2: No\n");
  }

  char *isPrime = "Yes";
  if (n < 2)
  {
    isPrime = "No";
  }
  else
  {
    for (int i = 2; i <= sqrt(n); i++)
    {
      if (n % i == 0)
      {
        isPrime = "No";
        break;
      }
    }
  }
  printf("Prime: %s\n", isPrime);

  char bin[33];
  int idx = 0;
  for (int i = 31; i >= 0; i--)
  {
    int check_bit = 1 << i;
    if (n & check_bit)
    {
      bin[idx++] = '1';
    }
    else if (idx > 0)
    {
      bin[idx++] = '0';
    }
  }
  bin[idx] = '\0';

  printf("Binary: %s", bin);
}