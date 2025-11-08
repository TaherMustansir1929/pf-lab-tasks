#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  double balance = 5000.0, dailyLimit = 2000.0;
  int transactions, pin, choice, correctPin = 1234, attempts = 3;

  for (int i = 1; i <= 4; i++)
  {
    if (i == 4)
    {
      printf("Account Locked! Too many failed attemps\n");
      exit(1);
    }
    printf("Enter PIN: ");
    scanf("%d", &pin);
    if (pin == correctPin)
    {
      printf("Welcome! Balance: %.2lf\n\n", balance);
      break;
    }
    else
    {
      printf("Incorrect PIN! Attempts left: %d\n", attempts - i);
    }
  }

  while (1)
  {
    printf("\n===Main Menu===\n");
    printf("1. Withdraw\n");
    printf("2. Deposit\n");
    printf("3. Calculate Interest\n");
    printf("4. Quick Double Check\n");
    printf("5. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      double amount, fee;
      printf("Enter amount: ");
      scanf("%lf", &amount);

      if (amount <= 0)
      {
        printf("Invalid amount!\n");
        continue;
      }

      if (amount > balance)
      {
        printf("Insufficient balance!\n");
        continue;
      }
      else if (amount > dailyLimit)
      {
        printf("Exceeded daily limit: %.2lf\n", dailyLimit);
        continue;
      }
      else
      {
        fee = amount > 100 ? (amount * 0.01) : 0;
        balance -= (amount + fee);
        printf("Withdrawal successful! Fee: %.2lf\nNew Balance: %.2lf\n", fee, balance);
        transactions++;
      }

      break;

    case 2:
      double deposit;
      printf("Enter deposit amount: ");
      scanf("%lf", &deposit);

      if (deposit <= 0)
      {
        printf("Invalid deposit!\n");
        continue;
      }
      else
      {
        if (deposit < 50)
        {
          printf("Minimum deposit amount is 50\n");
          continue;
        }
        else
        {
          balance += deposit;
          printf("Deposit successful! New Balance: %.2lf\n", balance);
          transactions++;
        }
      }

      break;

    case 3:
      double rate;
      int years;

      printf("Enter years: ");
      scanf("%d", &years);
      printf("Interest rate (%%): ");
      printf("%lf", &rate);

      double simple = (balance * years * rate) / 100;
      double compound = balance * (pow(1 + rate / 100, years) - 1);
      double futureValue = balance + compound;
      transactions++;

      printf("Simple Interest: %.2lf\n", simple);
      printf("Compound Interest: %.2lf\n", compound);
      printf("Future Value: %.2lf\n", futureValue);

      break;

    case 4:
      int check = (int)balance;
      printf("Quick double check: %d -> %d", check, check << 1);
      transactions++;

      break;

    case 5:
      printf("Exiting... total transactions: %d\n", transactions);
      if (transactions % 2 == 0)
      {
        printf("you made an even number of transactions\n");
      }
      else
      {
        printf("you made an even number of transactions\n");
      }
      exit(0);

    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
}