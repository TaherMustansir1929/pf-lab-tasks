#include <stdio.h>

void func1(int arr[][4], int rows) {
  printf("int arr[][4] - 2D array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
}

void func2(int *arr[], int rows) {
  printf("int *arr[] - array of pointers:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
}

void func3(int (*arr)[4], int rows) {
  printf("int (*arr)[4] - pointer to array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
}

int main() {
  int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  int row0[] = {1, 2, 3, 4};
  int row1[] = {5, 6, 7, 8};
  int row2[] = {9, 10, 11, 12};
  int *arr2[3] = {row0, row1, row2};

  int (*arr3)[4] = arr1;

  printf("Explanation:\n");
  printf("arr1[3][4]: Contiguous 2D array in memory\n");
  printf("*arr2[3]: Array of 3 pointers, each pointing to separate arrays\n");
  printf("(*arr3)[4]: Pointer to an array of 4 integers\n\n");

  func1(arr1, 3);
  printf("\n");
  func2(arr2, 3);
  printf("\n");
  func3(arr3, 3);

  return 0;
}