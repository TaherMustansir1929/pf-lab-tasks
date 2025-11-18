#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE *input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    printf("Error opening input file\n");
    return 1;
  }

  char words[100][50];
  int freq[100] = {0};
  int word_count = 0;
  int total_words = 0;
  int total_lines = 0;
  int total_chars = 0;
  char longest[50] = "";
  char shortest[50] = "";
  int first_word = 1;

  char ch;
  char current_word[50];
  int idx = 0;

  while ((ch = fgetc(input_file)) != EOF) {
    total_chars++;

    if (ch == '\n') {
      total_lines++;
    }

    if (isalpha(ch)) {
      current_word[idx++] = ch;
    } else {
      if (idx > 0) {
        current_word[idx] = '\0';
        total_words++;

        if (first_word || strlen(current_word) > strlen(longest)) {
          strcpy(longest, current_word);
        }
        if (first_word || strlen(current_word) < strlen(shortest)) {
          strcpy(shortest, current_word);
        }
        first_word = 0;

        int found = 0;
        for (int i = 0; i < word_count; i++) {
          if (strcmp(words[i], current_word) == 0) {
            freq[i]++;
            found = 1;
            break;
          }
        }

        if (!found) {
          strcpy(words[word_count], current_word);
          freq[word_count] = 1;
          word_count++;
        }

        idx = 0;
      }
    }
  }

  fclose(input_file);

  FILE *output_file = fopen("stats.txt", "w");
  if (output_file == NULL) {
    printf("Error opening output file\n");
    return 1;
  }

  fprintf(output_file, "Total words: %d\n", total_words);
  fprintf(output_file, "Total lines: %d\n", total_lines);
  fprintf(output_file, "Total characters: %d\n", total_chars);
  fprintf(output_file, "Longest word: %s\n", longest);
  fprintf(output_file, "Shortest word: %s\n", shortest);
  fprintf(output_file, "\nWord Frequency:\n");

  for (int i = 0; i < word_count; i++) {
    fprintf(output_file, "%s: %d\n", words[i], freq[i]);
  }

  fclose(output_file);

  printf("Statistics written to stats.txt\n");

  return 0;
}