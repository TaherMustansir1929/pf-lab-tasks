#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (isupper(text[i])) {
      text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
    } else if (islower(text[i])) {
      text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
    }
  }
}

void decrypt(char *text, int shift) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (isupper(text[i])) {
      text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
    } else if (islower(text[i])) {
      text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
    }
  }
}

int main() {
  int choice;
  char lines[10][100];
  int line_count;
  int shift;

  while (1) {
    printf("\n=== Caesar Cipher Menu ===\n");
    printf("1. Encrypt text and save to file\n");
    printf("2. Decrypt file and display\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
      printf("Enter number of lines: ");
      scanf("%d", &line_count);
      getchar();

      printf("Enter shift value: ");
      scanf("%d", &shift);
      getchar();

      printf("Enter text (line by line):\n");
      for (int i = 0; i < line_count; i++) {
        fgets(lines[i], 100, stdin);
        lines[i][strcspn(lines[i], "\n")] = '\0';
        encrypt(lines[i], shift);
      }

      FILE *file = fopen("encrypted.txt", "w");
      if (file == NULL) {
        printf("Error opening file\n");
        continue;
      }

      for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", lines[i]);
      }
      fclose(file);

      printf("Encrypted and saved to encrypted.txt\n");

    } else if (choice == 2) {
      printf("Enter shift value: ");
      scanf("%d", &shift);
      getchar();

      FILE *file = fopen("encrypted.txt", "r");
      if (file == NULL) {
        printf("Error opening file\n");
        continue;
      }

      printf("\nDecrypted text:\n");
      char line[100];
      while (fgets(line, 100, file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        decrypt(line, shift);
        printf("%s\n", line);
      }
      fclose(file);

    } else if (choice == 3) {
      break;
    } else {
      printf("Invalid choice\n");
    }
  }

  return 0;
}