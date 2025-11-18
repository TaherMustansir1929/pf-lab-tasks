#include <stdio.h>
#include <string.h>

int splitString(char *input, char result[][20], char delimiter) {
  int count = 0;
  int idx = 0;
  int i = 0;

  while (input[i] != '\0') {
    if (input[i] != delimiter) {
      result[count][idx++] = input[i];
    } else {
      if (idx > 0) {
        result[count][idx] = '\0';
        count++;
        idx = 0;
      }
    }
    i++;
  }

  if (idx > 0) {
    result[count][idx] = '\0';
    count++;
  }

  return count;
}

int main() {
  char input[100] = "apple,,banana,orange,,,grape";
  char result[10][20];
  char delimiter = ',';

  int token_count = splitString(input, result, delimiter);

  printf("Total tokens: %d\n", token_count);
  for (int i = 0; i < token_count; i++) {
    printf("Token %d: %s\n", i + 1, result[i]);
  }

  return 0;
}