#include <stdio.h>

int main() {
  int arr[10], swaps=0;
  for(int i=0; i<10; i++) {
    printf("Enter number #%d: ", i);
    scanf("%d", &arr[i]);
  }

  printf("Original array:");
  for(int i=0; i<10; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");

  for(int i=0; i<9; i++) {
    if(i%2==0) {
      if(!(arr[i] >= arr[i+1])) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        swaps++;
      }
    } else {
      if(!(arr[i] <= arr[i+1])) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        swaps++;
      }
    }
  }

  printf("Wave-arranged array:");
  for (int i = 0; i < 10; i++) {
      printf(" %d", arr[i]);
  }
  printf("\n");

  printf("Swaps needed: %d\n", swaps);

  return 0;
}