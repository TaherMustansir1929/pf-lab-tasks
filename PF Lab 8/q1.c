#include <stdio.h>

int main() {
  float mat[3][3], tr[3][3], cof[3][3], adj[3][3], inv[3][3];
  float det, minor;
  int i, j, m, n;

  printf("3x3 Matrix Stuff\n\n");

  printf("Enter 3x3 matrix vals:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%f", &mat[i][j]);
    }
  }

  printf("\n Transpose\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tr[i][j] = mat[j][i];
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%.2f\t", tr[i][j]);
    }
    printf("\n");
  }

  det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
        mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
        mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

  printf("\n Determinant\n");
  printf("Det = %.2f\n", det);

  printf("\n Cofactor Matrix\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      float tmp[2][2];
      int p = 0, q = 0;
      for (m = 0; m < 3; m++) {
        for (n = 0; n < 3; n++) {
          if (m != i && n != j) {
            tmp[p][q++] = mat[m][n];
            if (q == 2) {
              q = 0;
              p++;
            }
          }
        }
      }
      minor = tmp[0][0] * tmp[1][1] - tmp[0][1] * tmp[1][0];
      cof[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor;
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%.2f\t", cof[i][j]);
    }
    printf("\n");
  }

  printf("\n Adjoint Matrix\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      adj[i][j] = cof[j][i];
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%.2f\t", adj[i][j]);
    }
    printf("\n");
  }

  printf("\n Inverse Matrix\n");
  if (det == 0) {
    printf("Matrix singular. Inverse does not exist\n");
  } else {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        inv[i][j] = adj[i][j] / det;
      }
    }
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        printf("%.4f\t", inv[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
