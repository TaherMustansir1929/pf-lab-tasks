#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isPalindrome(char *word) {
  int len = strlen(word);

  for (int i = 0; i < len / 2; i++) {
    if (tolower(word[i]) != tolower(word[len - 1 - i])) {
      return 0;
    }
  }
  return 1;
}

int main() {
  FILE *input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    printf("Error opening input.txt\n");
    return 1;
  }

  FILE *palindrome_file = fopen("palindromes.txt", "w");
  FILE *normal_file = fopen("normal.txt", "w");

  if (palindrome_file == NULL || normal_file == NULL) {
    printf("Error opening output files\n");
    fclose(input_file);
    return 1;
  }

  char word[100];
  int palindrome_count = 0;
  int normal_count = 0;

  while (fscanf(input_file, "%s", word) != EOF) {
    if (isPalindrome(word)) {
      fprintf(palindrome_file, "%s\n", word);
      palindrome_count++;
    } else {
      fprintf(normal_file, "%s\n", word);
      normal_count++;
    }
  }

  fclose(input_file);
  fclose(palindrome_file);
  fclose(normal_file);

  printf("Total palindromes: %d\n", palindrome_count);
  printf("Total non-palindromes: %d\n", normal_count);

  return 0;
}