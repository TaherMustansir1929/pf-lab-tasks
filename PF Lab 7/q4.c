#include <stdio.h>

int main() {
  int both[12], either[12], neither[12];
  int both_count=0, either_count=0, neither_count=0;
  int both_sum=0, either_sum=0, neither_sum=0;
  int n;

  for(int i=0; i<12; i++) {
    printf("Enter number #%d: ", i);
    scanf("%d", &n);

    if(n%2==0 && n%3==0) {
      both[both_count] = n;
      both_count++;
      both_sum += n;
    } else if (n%2==0 || n%3==0) {
      either[either_count] = n;
      either_count++;
      either_sum += n;
    } else {
      neither[neither_count] = n;
      neither_count++;
      neither_sum += n;
    }
  }

  printf("\nBoth array count: %d,\nBoth array sum: %d\n", both_count, both_sum);
  printf("\neither array count: %d,\neither array sum: %d\n", either_count, either_sum);
  printf("\nneither array count: %d,\nneither array sum: %d\n", neither_count, neither_sum);
}