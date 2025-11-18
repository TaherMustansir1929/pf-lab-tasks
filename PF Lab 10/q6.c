#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
  int len = strlen(str);
  if (len > 0 && str[len - 1] == '\n') {
    len--;
    str[len] = '\0';
  }

  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

int main() {
  FILE *input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    printf("Error opening input file\n");
    return 1;
  }

  FILE *output_file = fopen("output.txt", "w");
  if (output_file == NULL) {
    printf("Error opening output file\n");
    fclose(input_file);
    return 1;
  }

  char line[101];

  while (fgets(line, 101, input_file) != NULL) {
    reverseString(line);
    fputs(line, output_file);
    fputs("\n", output_file);
  }

  fclose(input_file);
  fclose(output_file);

  printf("Lines reversed and written to output.txt\n");

  return 0;
}