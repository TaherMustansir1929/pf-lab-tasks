#include <stdio.h>

int main()
{
  double balance = 1000.0;
  int choice, quickCashChoice;
  double amount, fee;

  while (1)
  {
    printf("\n=== ATM MENU ===\n");
    printf("Current Balance: $%.2f\n", balance);
    printf("1. Check Balance\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Quick Cash\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      printf("Your balance is: $%.2f\n", balance);
    }
    else if (choice == 2)
    {
      printf("Enter withdrawal amount: $");
      scanf("%lf", &amount);
      if (amount <= 0)
      {
        printf("Invalid amount!\n");
      }
      else if ((int)amount % 10 != 0)
      {
        printf("Amount must be a multiple of $10!\n");
      }
      else if (amount > balance)
      {
        printf("Insufficient funds!\n");
      }
      else
      {
        fee = (amount > 100) ? 2.0 : 0.0;
        if (balance >= amount + fee)
        {
          balance -= (amount + fee);
          printf("Transaction successful!\n");
          if (fee > 0)
            printf("Transaction fee: $%.2f\n", fee);
          printf("Amount withdrawn: $%.2f\n", amount);
          printf("New balance: $%.2f\n", balance);
        }
        else
        {
          printf("Insufficient funds for fee!\n");
        }
      }
    }
    else if (choice == 3)
    {
      printf("Enter deposit amount: $");
      scanf("%lf", &amount);
      if (amount <= 0 || amount >= 5000)
      {
        printf("Deposit must be positive and less than $5000!\n");
      }
      else
      {
        balance += amount;
        printf("Deposit successful!\n");
        printf("New balance: $%.2f\n", balance);
      }
    }
    else if (choice == 4)
    {
      printf("Quick Cash Options:\n");
      printf("1. $20\n2. $50\n3. $100\n4. $200\n");
      printf("Enter choice: ");
      scanf("%d", &quickCashChoice);
      switch (quickCashChoice)
      {
      case 1:
        amount = 20;
        break;
      case 2:
        amount = 50;
        break;
      case 3:
        amount = 100;
        break;
      case 4:
        amount = 200;
        break;
      default:
        printf("Invalid quick cash option!\n");
        continue;
      }
      fee = (amount > 100) ? 2.0 : 0.0;
      if (amount > balance)
      {
        printf("Insufficient funds!\n");
      }
      else if (balance >= amount + fee)
      {
        balance -= (amount + fee);
        printf("Quick Cash successful!\n");
        if (fee > 0)
          printf("Transaction fee: $%.2f\n", fee);
        printf("Amount withdrawn: $%.2f\n", amount);
        printf("New balance: $%.2f\n", balance);
      }
      else
      {
        printf("Insufficient funds for fee!\n");
      }
    }
    else if (choice == 5)
    {
      printf("Thank you for using the ATM. Goodbye!\n");
      break;
    }
    else
    {
      printf("Invalid choice! Please try again.\n");
    }
  }
  return 0;
}