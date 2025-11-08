#include <stdio.h>

int main() {
  int mat[3][3][3];
  int i, j, k, l;
  int same;

  printf("3D Matrix Layer Similarity Analysis\n\n");

  printf("Enter elements for 3x3x3 matrix\n");
  for (i = 0; i < 3; i++) {
    printf("\n Layer %d\n", i);
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        printf("Element [%d][%d][%d]: ", i, j, k);
        scanf("%d", &mat[i][j][k]);
      }
    }
  }

  printf("\n Displaying All Layers\n");
  for (i = 0; i < 3; i++) {
    printf("\nLayer %d\n", i);
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        printf("%d\t", mat[i][j][k]);
      }
      printf("\n");
    }
  }

  printf("\n Layer Similarity Report\n");

  printf("\n Comparing Layer 0 and Layer 1\n");
  same = 1;
  for (j = 0; j < 3; j++) {
    for (k = 0; k < 3; k++) {
      if (mat[0][j][k] != mat[1][j][k]) {
        same = 0;
        break;
      }
    }
    if (!same)
      break;
  }

  if (same) {
    printf("Result: Identical\n");
  } else {
    printf("Result: Distinct\n");
    printf("Differences found\n");
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if (mat[0][j][k] != mat[1][j][k]) {
          printf("Position [%d][%d]: L0=%d, L1=%d\n", j, k, mat[0][j][k],
                 mat[1][j][k]);
        }
      }
    }
  }

  printf("\n Comparing Layer 0 and Layer 2\n");
  same = 1;
  for (j = 0; j < 3; j++) {
    for (k = 0; k < 3; k++) {
      if (mat[0][j][k] != mat[2][j][k]) {
        same = 0;
        break;
      }
    }
    if (!same)
      break;
  }

  if (same) {
    printf("Result: Identical\n");
  } else {
    printf("Result: Distinct\n");
    printf("Differences found\n");
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if (mat[0][j][k] != mat[2][j][k]) {
          printf("Position [%d][%d]: L0=%d, L2=%d\n", j, k, mat[0][j][k],
                 mat[2][j][k]);
        }
      }
    }
  }

  printf("\n Comparing Layer 1 and Layer 2\n");
  same = 1;
  for (j = 0; j < 3; j++) {
    for (k = 0; k < 3; k++) {
      if (mat[1][j][k] != mat[2][j][k]) {
        same = 0;
        break;
      }
    }
    if (!same)
      break;
  }

  if (same) {
    printf("Result: Identical\n");
  } else {
    printf("Result: Distinct\n");
    printf("Differences found\n");
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if (mat[1][j][k] != mat[2][j][k]) {
          printf("Position [%d][%d]: L1=%d, L2=%d\n", j, k, mat[1][j][k],
                 mat[2][j][k]);
        }
      }
    }
  }

  printf("\n Overall Similarity Summary\n");
  int allsame = 1;
  for (i = 0; i < 2; i++) {
    for (l = i + 1; l < 3; l++) {
      for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
          if (mat[i][j][k] != mat[l][j][k]) {
            allsame = 0;
            break;
          }
        }
        if (!allsame)
          break;
      }
      if (!allsame)
        break;
    }
    if (!allsame)
      break;
  }

  if (allsame) {
    printf("All three layers identical\n");
  } else {
    printf("Layers distinct (not all identical)\n");
  }

  return 0;
}
