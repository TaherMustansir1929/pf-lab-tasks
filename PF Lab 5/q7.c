#include <stdio.h>
#include <stdlib.h>

int main()
{
  int time, hours = 0, minutes = 0, seconds = 0;

  printf("Enter total seconds: ");
  scanf("%d", &time);

  if (time < 0)
  {
    printf("Invalid time\n");
    exit(1);
  }

  if (time >= 3600)
  {
    hours = time / 3600;
    time %= 3600;
    minutes = time / 60;
    time %= 60;
  }
  if (time >= 60)
  {
    minutes = time / 60;
    time %= 60;
  }
  seconds = time;

  printf("Time breakdown:\n");
  printf("%d hour(s)\n", hours);
  printf("%d minute(s)\n", minutes);
  printf("%d second(s)\n", seconds);

  printf("\nFormatted: %d:%d:%d", hours, minutes, seconds);
}