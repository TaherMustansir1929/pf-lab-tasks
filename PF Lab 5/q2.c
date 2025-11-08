#include <stdio.h>
#include <stdlib.h>

int main()
{
  int marks, attendance;
  char *status;

  printf("Enter marks: ");
  scanf("%d", &marks);
  printf("Enter attendance %%: ");
  scanf("%d", &attendance);
  printf("Original Marks: %d\n", marks);

  if (marks < 0 || marks > 100)
  {
    printf("Invalid input!\n");
    exit(1);
  }

  if (marks >= 50)
  {
    if (attendance >= 95)
    {
      marks += 5;
    }
    else if (attendance >= 75)
    {
      marks += 3;
    }
    status = "PASS";
  }
  else
  {
    if (attendance >= 95)
    {
      marks += 7;
    }
    if (marks >= 50)
    {
      status = "PASS";
    }
    else
    {
      status = "FAIL";
    }
  }

  printf("Attendance Bonus: %d\n", attendance);
  printf("Final marks: %d\n\n", marks);
  printf("Status: %s\n", status);
}