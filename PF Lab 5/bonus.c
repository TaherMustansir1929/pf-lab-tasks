#include <stdio.h>

int main()
{
  int num, roll, roll2, score = 0;

  printf("Enter a number for dice roll: ");
  scanf("%d", &num);

  roll = (num % 6) + 1;
  printf("Dice shows: %d\n", roll);

  if (roll == 6)
  {
    printf("Great! You get a bonus roll!\n");
    printf("Enter another number: ");
    scanf("%d", &num);

    roll2 = (num % 6) + 1;
    printf("Dice shows: %d\n", roll2);

    if (roll2 == 6)
    {
      printf("JACKPOT! Double 6s!\n");
      score = 100;
      int finalScore = score << 1;
      printf("Points earned: %d\n", score);
      printf("Multiplier active: 2x (using bitwise shift)\n");
      printf("Final score: %d\n", finalScore);
    }
    else
    {
      score = (roll2 == 1) ? 0 : 20;
      printf("Points earned: %d\n", score);
    }
  }
  else if (roll == 1)
  {
    printf("Oops! Rolled a 1. Lose your turn.\n");
    score = 0;
  }
  else
  {
    score = (roll > 3) ? 10 : 5;
    printf("Points earned: %d\n", score);
  }

  return 0;
}
