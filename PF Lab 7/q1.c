#include <stdio.h>

int main() {
  int arr[15];
  int len = sizeof(arr) / sizeof(arr[0]);
  printf("len: %d\n", len);

  for (int i = 0; i < len; i++) {
    printf("Enter element #%d: ", i+1);
    scanf("%d", &arr[i]);
  }

  for(int i=0; i<len/2; i++) {
    arr[len-i-1] = arr[i];
  }

  printf("Output:");
  for(int i=0; i<len; i++) {
    printf(" %d", arr[i]);
    if(i == len-1) printf("\n");
  }

  int search;
  printf("Search a number's position: ");
  scanf("%d", &search);

  for(int i=0; i<len/2; i++) {
    if(arr[i] == search) {
      printf("The number is present on index %d and %d\n", i, len-i-1);
    }
  }
}