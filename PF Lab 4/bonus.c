#include <stdio.h>

void print_choice(int choice)
{
  if (choice == 1)
  {
    printf("Rock\n");
    printf("   _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
  }
  else if (choice == 2)
  {
    printf("Paper\n");
    printf("   _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("          _______)\n");
    printf("         _______)\n");
    printf("---.__________)\n");
  }
  else if (choice == 3)
  {
    printf("Scissors\n");
    printf("   _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("       __________)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
  }
}

int main()
{
  int userChoice, luckyNumber, computerChoice;

  printf("Enter your choice (1=Rock, 2=Paper, 3=Scissors): ");
  scanf("%d", &userChoice);
  if (userChoice < 1 || userChoice > 3)
  {
    printf("Invalid choice!\n");
    return 1;
  }

  printf("Enter your lucky number: ");
  scanf("%d", &luckyNumber);

  computerChoice = (luckyNumber % 3) + 1;

  printf("\nYou chose: ");
  print_choice(userChoice);

  printf("\nComputer chose: ");
  print_choice(computerChoice);

  if (userChoice == computerChoice)
  {
    printf("\nIt's a draw!\n");
  }
  else if ((userChoice == 1 && computerChoice == 3) ||
           (userChoice == 2 && computerChoice == 1) ||
           (userChoice == 3 && computerChoice == 2))
  {
    printf("\nYou win! ");
    if (userChoice == 1 && computerChoice == 3)
      printf("Rock crushes Scissors!\n");
    else if (userChoice == 2 && computerChoice == 1)
      printf("Paper covers Rock!\n");
    else if (userChoice == 3 && computerChoice == 2)
      printf("Scissors cut Paper!\n");
  }
  else
  {
    printf("\nComputer wins! ");
    if (computerChoice == 1 && userChoice == 3)
      printf("Rock crushes Scissors!\n");
    else if (computerChoice == 2 && userChoice == 1)
      printf("Paper covers Rock!\n");
    else if (computerChoice == 3 && userChoice == 2)
      printf("Scissors cut Paper!\n");
  }

  return 0;
}