#include<stdio.h>

int main() {
  int arr[8];
  int target, pairs=0;

  for(int i=0; i<8; i++) {
    printf("Enter number #%d: ", i);
    scanf("%d", &arr[i]);
  }

  printf("Enter target sum: ");
  scanf("%d", &target);

  printf("Pairs: \n");
  for(int i=0; i<8; i++) {
    for(int j=i+1; j<8; j++) {
      if(arr[i] + arr[j] == target) {
        printf("(%d, %d)\n", arr[i], arr[j]);
        pairs++;
      }
    }
  }

  if (pairs == 0) {
    printf("No pairs found with the target sum of %d.\n", target);
} else {
    printf("\nTotal pairs found: %d\n", pairs);
}
}