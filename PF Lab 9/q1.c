#include <stdio.h>

int mysteryAccess(int *ptr, int rows, int cols, int i, int j) {
  return *(ptr + i * cols + j);
}

void printSpiral(int *ptr, int rows, int cols) {
  int top = 0, bottom = rows - 1;
  int left = 0, right = cols - 1;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++)
      printf("%d ", *(ptr + top * cols + i));
    top++;

    for (int i = top; i <= bottom; i++)
      printf("%d ", *(ptr + i * cols + right));
    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; i--)
        printf("%d ", *(ptr + bottom * cols + i));
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        printf("%d ", *(ptr + i * cols + left));
      left++;
    }
  }
  printf("\n");
}

int main() {
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  printf("Element at (1,2): %d\n", mysteryAccess(&arr[0][0], 3, 3, 1, 2));
  printf("Spiral pattern: ");
  printSpiral(&arr[0][0], 3, 3);

  return 0;
}