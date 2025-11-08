#include <stdio.h>

int main() {
  int m[5][5];
  int i, j;
  int student_total[5] = {0};
  float student_avg[5];
  int high = 0, low = 500;
  int top, weak;
  int sub_max[5], sub_top[5];

  printf("\n student marks analysis\n\n");

  printf("enter marks for 5 students 5 subs\n");
  for (i = 0; i < 5; i++) {
    printf("\n student %d\n", i + 1);
    for (j = 0; j < 5; j++) {
      printf("sub %d: ", j + 1);
      scanf("%d", &m[i][j]);
    }
  }

  printf("\n marks table\n");
  printf("stu\t1\t2\t3\t4\t5\n");
  for (i = 0; i < 5; i++) {
    printf("%d\t", i + 1);
    for (j = 0; j < 5; j++)
      printf("%d\t", m[i][j]);
    printf("\n");
  }

  printf("\n student wise\n");
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++)
      student_total[i] += m[i][j];
    student_avg[i] = student_total[i] / 5.0;
    printf("stu %d total %d avg %.2f\n", i + 1, student_total[i],
           student_avg[i]);
  }

  for (i = 0; i < 5; i++) {
    if (student_total[i] > high) {
      high = student_total[i];
      top = i;
    }
    if (student_total[i] < low) {
      low = student_total[i];
      weak = i;
    }
  }

  printf("\n overall performance\n");
  printf("top stu %d total %d avg %.2f\n", top + 1, high, student_avg[top]);
  printf("low stu %d total %d avg %.2f\n", weak + 1, low, student_avg[weak]);

  printf("\n subject toppers\n");
  for (j = 0; j < 5; j++) {
    sub_max[j] = m[0][j];
    sub_top[j] = 0;
    for (i = 1; i < 5; i++) {
      if (m[i][j] > sub_max[j]) {
        sub_max[j] = m[i][j];
        sub_top[j] = i;
      }
    }
    printf("sub %d top stu %d marks %d\n", j + 1, sub_top[j] + 1, sub_max[j]);
  }

  printf("\n subject avg\n");
  for (j = 0; j < 5; j++) {
    int sum = 0;
    for (i = 0; i < 5; i++)
      sum += m[i][j];
    printf("sub %d avg %.2f\n", j + 1, sum / 5.0);
  }

  printf("\n performance catergory\n");
  for (i = 0; i < 5; i++) {
    printf("stu %d ", i + 1);
    if (student_avg[i] >= 90)
      printf("A+\n");
    else if (student_avg[i] >= 80)
      printf("A\n");
    else if (student_avg[i] >= 70)
      printf("B\n");
    else if (student_avg[i] >= 60)
      printf("C\n");
    else if (student_avg[i] >= 50)
      printf("D\n");
    else
      printf("F\n");
  }

  return 0;
}
