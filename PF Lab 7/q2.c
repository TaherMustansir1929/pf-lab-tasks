#include <stdio.h>
#include <stdbool.h>

int main() {
  int prime[20], prime_len = 0;
  int composite[20], composite_len = 0;
  int n;

  for (int i = 0; i < 20; i++) {
    printf("Enter number #%d: ", i + 1);
    scanf("%d", &n);

    if (n <= 1) {
      printf("Invalid number! Must be above 1\n");
      i--;
      continue;
    }

    bool is_prime = true;
    for (int j = 2; j <= n / 2; j++) {
      if (n % j == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      prime[prime_len] = n;
      prime_len++;
    } else {
      composite[composite_len] = n;
      composite_len++;
    }
  }

  float prime_avg = 0.0f;
  int prime_sum = 0;
  if (prime_len > 0) {
    for (int i = 0; i < prime_len; i++) {
      prime_sum += prime[i];
    }
    prime_avg = (float)prime_sum / prime_len;
  }

  float composite_avg = 0.0f;
  int composite_sum = 0;
  if (composite_len > 0) {
    for (int i = 0; i < composite_len; i++) {
      composite_sum += composite[i];
    }
    composite_avg = (float)composite_sum / composite_len;
  }

  printf("\nPrime Numbers (%d):", prime_len);
  for (int i = 0; i < prime_len; i++) {
    printf(" %d", prime[i]);
  }
  printf("\nAverage: %.2f\n", prime_avg);

  printf("\nComposite Numbers (%d):", composite_len);
  for (int i = 0; i < composite_len; i++) {
    printf(" %d", composite[i]);
  }
  printf("\nAverage: %.2f\n", composite_avg);
  
  return 0;
}