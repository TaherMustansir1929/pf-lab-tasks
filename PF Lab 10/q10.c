#include <stdio.h>
#include <string.h>

int main() {
  char arr1[10] = "Hello";
  char *arr2 = "Hello";
  char arr3[10];
  strcpy(arr3, "Hello");

  printf("=== String Memory Detective ===\n\n");

  printf("--- Declaration Types ---\n");
  printf("arr1[10] = \"Hello\" - Array on stack, modifiable\n");
  printf("*arr2 = \"Hello\" - Pointer to string literal, read-only\n");
  printf("arr3[10] then strcpy - Array on stack, modifiable\n\n");

  printf("--- Addresses ---\n");
  printf("arr1 address: %p\n", (void *)arr1);
  printf("arr2 address: %p (points to literal)\n", (void *)arr2);
  printf("arr3 address: %p\n", (void *)arr3);
  printf("\n");

  printf("--- Individual Character Addresses ---\n");
  printf("arr1[0] address: %p\n", (void *)&arr1[0]);
  printf("arr1[1] address: %p\n", (void *)&arr1[1]);
  printf("arr2[0] address: %p\n", (void *)&arr2[0]);
  printf("arr3[0] address: %p\n", (void *)&arr3[0]);
  printf("\n");

  printf("--- Modification Attempts ---\n");

  arr1[0] = 'h';
  printf("arr1[0] = 'h' - SUCCESS\n");
  printf("arr1 is now: %s\n", arr1);
  printf("Explanation: arr1 is on stack, fully modifiable\n\n");

  printf("arr2[0] = 'h' - WILL CAUSE SEGMENTATION FAULT\n");
  printf("Explanation: arr2 points to string literal in read-only memory\n");
  printf("SKIPPING THIS MODIFICATION TO AVOID CRASH\n\n");

  arr3[0] = 'h';
  printf("arr3[0] = 'h' - SUCCESS\n");
  printf("arr3 is now: %s\n", arr3);
  printf("Explanation: arr3 copied string to stack, modifiable\n\n");

  printf("--- Bounds Testing ---\n");
  printf("arr1 size: 10 bytes\n");
  printf("Writing beyond bounds is undefined behavior\n");
  arr1[9] = 'X';
  printf("arr1[9] = 'X' - May work but dangerous\n");
  printf("arr1[15] = 'Y' - Buffer overflow, corrupts memory\n\n");

  printf("=== Summary ===\n");
  printf("1. String literals are in read-only memory\n");
  printf("2. Arrays on stack are modifiable\n");
  printf("3. Pointers to literals should not be modified\n");
  printf("4. strcpy copies to modifiable memory\n");
  printf("5. Exceeding bounds causes undefined behavior\n");

  return 0;
}