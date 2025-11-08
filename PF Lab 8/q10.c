#include <stdio.h>

int main() {
  int wh[3][3][3];
  int i, j, k;
  int floors[3] = {0, 0, 0};
  int total = 0;
  int max_floor = 0;
  int empty_c = 0;

  printf("Warehouse System\n\n");

  printf("Enter data:\n");
  printf("(3x3x3)\n\n");

  for (i = 0; i < 3; i++) {
    printf(" Floor %d \n", i + 1);
    for (j = 0; j < 3; j++) {
      printf("Shelf %d:\n", j + 1);
      for (k = 0; k < 3; k++) {
        printf("  Sec %d: ", k + 1);
        scanf("%d", &wh[i][j][k]);
      }
    }
    printf("\n");
  }

  printf("\n Warehouse Layout\n\n");
  for (i = 0; i < 3; i++) {
    printf("FLOOR %d:\n", i + 1);
    printf("Shelf\tSec1\tSec2\tSec3\n");
    printf("-----\t----\t----\t----\n");
    for (j = 0; j < 3; j++) {
      printf("  %d\t", j + 1);
      for (k = 0; k < 3; k++) {
        printf("%d\t", wh[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  printf("\n Floor Analysis\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        floors[i] += wh[i][j][k];
      }
    }
    total += floors[i];
    printf("Floor %d: %d items\n", i + 1, floors[i]);
  }

  for (i = 1; i < 3; i++) {
    if (floors[i] > floors[max_floor]) {
      max_floor = i;
    }
  }

  printf("\n Max Stock\n");
  printf("Floor %d has most\n", max_floor + 1);
  printf("Items: %d\n", floors[max_floor]);

  printf("\n Empty Sections\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if (wh[i][j][k] == 0) {
          printf("F%d, S%d, S%d: EMPTY\n", i + 1, j + 1, k + 1);
          empty_c++;
        }
      }
    }
  }

  if (empty_c == 0) {
    printf("No empty sections\n");
  } else {
    printf("\nTotal Empty: %d\n", empty_c);
  }

  printf("\n Shelf Analysis\n");
  for (i = 0; i < 3; i++) {
    printf("\nFloor %d:\n", i + 1);
    for (j = 0; j < 3; j++) {
      int s_tot = 0;
      for (k = 0; k < 3; k++) {
        s_tot += wh[i][j][k];
      }
      printf("  Shelf %d: %d items", j + 1, s_tot);
      if (s_tot == 0) {
        printf(" [EMPTY]");
      } else if (s_tot < 10) {
        printf(" [LOW]");
      } else if (s_tot > 50) {
        printf(" [HIGH]");
      }
      printf("\n");
    }
  }

  printf("\n Overall Stats\n");
  printf("Total: %d\n", total);
  printf("Avg Floor: %.2f\n", total / 3.0);
  printf("Avg Shelf: %.2f\n", total / 9.0);
  printf("Avg Sec: %.2f\n", total / 27.0);

  printf("\n Storage Use\n");
  int tot_sec = 27;
  int occ_sec = tot_sec - empty_c;
  float util = (occ_sec / (float)tot_sec) * 100;
  printf("Occupied: %d/%d\n", occ_sec, tot_sec);
  printf("Use: %.2f%%\n", util);

  printf("\n Distribution\n");
  for (i = 0; i < 3; i++) {
    if (total > 0) {
      float f_perc = (floors[i] / (float)total) * 100;
      printf("Floor %d: %.2f%%\n", i + 1, f_perc);
    } else {
      printf("Floor %d: 0.00%%\n", i + 1);
    }
  }

  printf("\n Alerts\n");
  int alrt = 0;

  if (empty_c > 9) {
    printf("Warn: many empty\n");
    alrt++;
  }

  for (i = 0; i < 3; i++) {
    if (floors[i] == 0) {
      printf("Critical: F%d empty\n", i + 1);
      alrt++;
    }
  }

  int min_f = 0;
  for (i = 1; i < 3; i++) {
    if (floors[i] < floors[min_f]) {
      min_f = i;
    }
  }

  if (total > 0 && floors[min_f] < total * 0.15) {
    printf("Notice: F%d low stock\n", min_f + 1);
    alrt++;
  }

  if (alrt == 0) {
    printf("No alerts. All ok\n");
  }

  return 0;
}