#include <stdio.h>

int compareInt(void *a, void *b) { return (*(int *)a > *(int *)b) ? 1 : 0; }

int compareFloat(void *a, void *b) {
  return (*(float *)a > *(float *)b) ? 1 : 0;
}

int compareChar(void *a, void *b) { return (*(char *)a > *(char *)b) ? 1 : 0; }

void *findMax(void *arr, int size, int elem_size,
              int (*compare)(void *, void *)) {
  void *max = arr;
  for (int i = 1; i < size; i++) {
    void *current = (char *)arr + i * elem_size;
    if (compare(current, max)) {
      max = current;
    }
  }
  return max;
}

int main() {
  int int_arr[] = {3, 7, 2, 9, 1};
  int *max_int = (int *)findMax(int_arr, 5, sizeof(int), compareInt);
  printf("Max int: %d\n", *max_int);

  float float_arr[] = {3.5, 7.2, 2.1, 9.8, 1.4};
  float *max_float =
      (float *)findMax(float_arr, 5, sizeof(float), compareFloat);
  printf("Max float: %.1f\n", *max_float);

  char char_arr[] = {'d', 'a', 'z', 'c', 'm'};
  char *max_char = (char *)findMax(char_arr, 5, sizeof(char), compareChar);
  printf("Max char: %c\n", *max_char);

  return 0;
}