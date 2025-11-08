#include <stdio.h>

int main() {
  float matrix1[3][3], matrix2[3][3], result[3][3];
  int rows1, cols1, rows2, cols2;
  int i, j, k;

  printf("Matrix Multiplication\n\n");

  printf("Enter dimensions of first matrix\n");
  printf("Rows (max 3): ");
  scanf("%d", &rows1);
  printf("Columns (max 3): ");
  scanf("%d", &cols1);

  printf("\nEnter dimensions of second matrix\n");
  printf("Rows (max 3): ");
  scanf("%d", &rows2);
  printf("Columns (max 3): ");
  scanf("%d", &cols2);

  if (cols1 != rows2) {
    printf("\nMatrix multiplication not possible\n");
    printf("Columns in Matrix 1 (%d) must equal Rows in Matrix 2 (%d)\n", cols1,
           rows2);
    return 1;
  }

  printf("\n Enter First Matrix\n");
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols1; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%f", &matrix1[i][j]);
    }
  }

  printf("\n Enter Second Matrix\n");
  for (i = 0; i < rows2; i++) {
    for (j = 0; j < cols2; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%f", &matrix2[i][j]);
    }
  }

  printf("\nFirst Matrix (%dx%d)\n", rows1, cols1);
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols1; j++) {
      printf("%.2f\t", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\nSecond Matrix (%dx%d)\n", rows2, cols2);
  for (i = 0; i < rows2; i++) {
    for (j = 0; j < cols2; j++) {
      printf("%.2f\t", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\n Performing Multiplication\n");
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  printf("\nResultant Matrix (%dx%d)\n", rows1, cols2);
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols2; j++) {
      printf("%.2f\t", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}
