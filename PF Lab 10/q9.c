#include <stdio.h>
#include <string.h>

int main() {
  FILE *input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    printf("Error opening input file\n");
    return 1;
  }

  char lines[100][200];
  int line_count = 0;

  while (fgets(lines[line_count], 200, input_file) != NULL &&
         line_count < 100) {
    line_count++;
  }
  fclose(input_file);

  char search_word[50], replace_word[50];
  printf("Enter word to search: ");
  scanf("%s", search_word);
  printf("Enter replacement word: ");
  scanf("%s", replace_word);

  int replacement_count = 0;
  char result[100][200];

  for (int i = 0; i < line_count; i++) {
    char temp[200] = "";
    char *pos = lines[i];
    char *found;

    while ((found = strstr(pos, search_word)) != NULL) {
      strncat(temp, pos, found - pos);
      strcat(temp, replace_word);
      pos = found + strlen(search_word);
      replacement_count++;
    }
    strcat(temp, pos);
    strcpy(result[i], temp);
  }

  FILE *output_file = fopen("output.txt", "w");
  if (output_file == NULL) {
    printf("Error opening output file\n");
    return 1;
  }

  for (int i = 0; i < line_count; i++) {
    fputs(result[i], output_file);
  }
  fclose(output_file);

  printf("Total replacements made: %d\n", replacement_count);
  printf("Modified content written to output.txt\n");

  return 0;
}