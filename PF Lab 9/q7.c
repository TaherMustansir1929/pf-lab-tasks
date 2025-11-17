#include <stdio.h>
#include <stdlib.h>

int **rotateMatrix90(int **matrix, int n) {
  int **rotated = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    rotated[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - 1 - i] = matrix[i][j];
    }
  }

  return rotated;
}

void printMatrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void freeMatrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  int n = 3;
  int **matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }

  int val = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = val++;
    }
  }

  printf("Original matrix:\n");
  printMatrix(matrix, n);

  int **rotated = rotateMatrix90(matrix, n);

  printf("\nRotated 90 degrees clockwise:\n");
  printMatrix(rotated, n);

  freeMatrix(matrix, n);
  freeMatrix(rotated, n);

  return 0;
}