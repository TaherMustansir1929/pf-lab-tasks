#include<stdio.h>
#include <string.h>

int main() {
  char str[255];
  printf("Enter a string: ");
  scanf("%[^\n]", str);

  int shift;
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  for (int i=0; i<strlen(str); i++) {
    if(str[i] < 65 || str[i] > 122) continue;
    str[i] += shift;
  }

  printf("Encrypted string: %s\n", str);

  printf("Do you want to decrypt it? (y/n): ");
  char opt;
  scanf(" %c", &opt);
  if(opt == 'y') {
    for(int i=0; i<strlen(str); i++) {
      if(str[i] < 65 || str[i] > 122) continue;
      str[i] -= shift;
    }

    printf("Decrypted string: %s\n", str);
  }
}