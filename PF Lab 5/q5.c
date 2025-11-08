#include <stdio.h>

int main()
{
  int amount, age, base_discount, age_discount;

  printf("Enter amount: ");
  scanf("%d", &amount);
  printf("Enter age: ");
  scanf("%d", &age);

  base_discount = (amount > 1000) ? 10 : 5;
  printf("Base Discount: %d%%\n", base_discount);

  age_discount = (age >= 60) ? (amount > 500) ? 15 : 10 : 0;
  printf("Senior citizen Discount: %d%%\n", age_discount);

  double total_discount = base_discount + age_discount;
  printf("Total Discount: %.0lf%%\n", total_discount);
  printf("Amount after discount: %.0lf\n\n", (double)(amount * (1 - total_discount / 100)));
  printf("You saved: %.0lf", (double)(amount * (total_discount / 100)));
}