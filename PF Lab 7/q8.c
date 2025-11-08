#include <stdio.h>

int main() {
  int arr1[6], arr2[6];
  int merge[12];

  for(int i=0; i<6; i++) {
    printf("Enter element #%d of arr1: ", i);
    scanf("%d", &arr1[i]);
  }
  for(int i=0; i<6; i++) {
    printf("Enter element #%d of arr2: ", i);
    scanf("%d", &arr2[i]);
  }

  for(int i=0; i<6; i++) {
    merge[i*2] = arr1[i];
    merge[i*2+1] = arr2[i];
  }

  printf("Zigzag Pattern: ");
  for(int i=0; i<12; i++) printf("%d ", merge[i]);
  printf("\n");

  for (int i = 0; i < 12 - 1; i++) {
    for (int j = 0; j < 12 - i - 1; j++) {
      if (merge[j] > merge[j + 1]) {
          int temp = merge[j];
          merge[j] = merge[j + 1];
          merge[j + 1] = temp;
      }
    }
  }

  int middle_element1 = merge[(12 / 2) - 1];
  int middle_element2 = merge[12 / 2];

  float median = (float)(middle_element1 + middle_element2) / 2.0f;

  printf("Median value of the merged array: %.1f\n", median);

  return 0;
}