#include <stdio.h>

int main() {
  int arr3d[3][3][3];
  int i, j, k;
  int layer_total, all_total = 0, total_elements = 0;
  float layer_avg, all_avg;

  printf("3D Array Analysis (3x3x3)\n\n");

  printf("Enter elements for 3x3x3 array\n");
  for (i = 0; i < 3; i++) {
    printf("\n Layer %d\n", i);
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        printf("Element [%d][%d][%d]: ", i, j, k);
        scanf("%d", &arr3d[i][j][k]);
      }
    }
  }

  printf("\n 3D Array Structure\n");
  for (i = 0; i < 3; i++) {
    printf("\nLayer %d\n", i);
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        printf("%d\t", arr3d[i][j][k]);
      }
      printf("\n");
    }
  }

  printf("\n Layer-wise Analysis\n");
  for (i = 0; i < 3; i++) {
    layer_total = 0;
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        layer_total += arr3d[i][j][k];
      }
    }
    layer_avg = layer_total / 9.0;
    all_total += layer_total;
    total_elements += 9;

    printf("\nLayer %d\n", i);
    printf("Total: %d\n", layer_total);
    printf("Avg: %.2f\n", layer_avg);
  }

  all_avg = all_total / (float)total_elements;

  printf("\n Overall Data Insights\n");
  printf("Total elements: %d\n", total_elements);
  printf("Overall sum: %d\n", all_total);
  printf("Overall avg: %.2f\n", all_avg);

  int min = arr3d[0][0][0];
  int max = arr3d[0][0][0];

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if (arr3d[i][j][k] < min)
          min = arr3d[i][j][k];
        if (arr3d[i][j][k] > max)
          max = arr3d[i][j][k];
      }
    }
  }

  printf("Min value: %d\n", min);
  printf("Max value: %d\n", max);

  return 0;
}
