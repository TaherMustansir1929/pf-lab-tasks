#include <stdio.h>
#include <stdlib.h>

int ascending(int a, int b) { return a > b; }

int descending(int a, int b) { return a < b; }

int byAbsolute(int a, int b) { return abs(a) > abs(b); }

void customSort(int *arr, int size, int (*condition)(int, int)) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (condition(arr[j], arr[j + 1])) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr1[] = {5, -3, 8, -1, 2, -7};
  int arr2[] = {5, -3, 8, -1, 2, -7};
  int arr3[] = {5, -3, 8, -1, 2, -7};
  int size = 6;

  printf("Original: ");
  printArray(arr1, size);

  customSort(arr1, size, ascending);
  printf("Ascending: ");
  printArray(arr1, size);

  customSort(arr2, size, descending);
  printf("Descending: ");
  printArray(arr2, size);

  customSort(arr3, size, byAbsolute);
  printf("By absolute value: ");
  printArray(arr3, size);

  return 0;
}