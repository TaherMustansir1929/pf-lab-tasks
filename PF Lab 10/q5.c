#include <stdio.h>
#include <string.h>

void sortAlphabetically(char arr[][50], int n) {
  char temp[50];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(arr[j], arr[j + 1]) > 0) {
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j + 1]);
        strcpy(arr[j + 1], temp);
      }
    }
  }
}

void sortByLength(char arr[][50], int n) {
  char temp[50];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strlen(arr[j]) > strlen(arr[j + 1])) {
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j + 1]);
        strcpy(arr[j + 1], temp);
      }
    }
  }
}

int main() {
  char names[10][50];
  int n;

  printf("Enter number of names (max 10): ");
  scanf("%d", &n);
  getchar();

  printf("Enter %d names:\n", n);
  for (int i = 0; i < n; i++) {
    fgets(names[i], 50, stdin);
    names[i][strcspn(names[i], "\n")] = '\0';
  }

  printf("\nBefore sorting:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", names[i]);
  }

  char names_copy[10][50];
  for (int i = 0; i < n; i++) {
    strcpy(names_copy[i], names[i]);
  }

  sortAlphabetically(names, n);
  printf("\nAfter alphabetical sorting:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", names[i]);
  }

  sortByLength(names_copy, n);
  printf("\nAfter sorting by length:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", names_copy[i]);
  }

  return 0;
}