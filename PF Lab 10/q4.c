#include <stdio.h>

void myStrcat_array(char *dest, char *src) {
  int i = 0;
  while (dest[i] != '\0') {
    i++;
  }

  int j = 0;
  while (src[j] != '\0') {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
}

void myStrcat_pointer(char *dest, char *src) {
  while (*dest != '\0') {
    dest++;
  }

  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}

int main() {
  char str1[100] = "Hello ";
  char str2[100] = "World";

  myStrcat_array(str1, str2);
  printf("Array indexing result: %s\n", str1);

  char str3[100] = "Good ";
  char str4[100] = "Morning";

  myStrcat_pointer(str3, str4);
  printf("Pointer arithmetic result: %s\n", str3);

  printf("\nExplanation:\n");
  printf("Array indexing: Uses subscript operator, may involve address "
         "calculation each time\n");
  printf(
      "Pointer arithmetic: Direct memory access, typically more efficient\n");
  printf("Pointer version has fewer operations and is generally faster\n");

  return 0;
}