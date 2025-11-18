#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "Hello";
  char str2[] = "Hello";
  char *str3 = "Hello";
  char *str4 = "Hello";

  printf("=== String Comparison Demonstrations ===\n\n");

  printf("str1[] = \"Hello\" (array)\n");
  printf("str2[] = \"Hello\" (array)\n");
  printf("str3* = \"Hello\" (pointer to literal)\n");
  printf("str4* = \"Hello\" (pointer to literal)\n\n");

  printf("--- Using == operator ---\n");
  printf("str1 == str2: %d\n", str1 == str2);
  printf("Explanation: Compares addresses, not content. Different arrays have "
         "different addresses.\n\n");

  printf("str3 == str4: %d\n", str3 == str4);
  printf("Explanation: Both may point to same string literal in read-only "
         "memory.\n\n");

  printf("--- Using strcmp() ---\n");
  printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));
  printf("Explanation: Compares actual content character by character. Returns "
         "0 for equal strings.\n\n");

  printf("strcmp(str3, str4): %d\n", strcmp(str3, str4));
  printf(
      "Explanation: Also compares content. Returns 0 for equal strings.\n\n");

  printf("--- Pointer Comparison ---\n");
  printf("&str1[0] == &str2[0]: %d\n", &str1[0] == &str2[0]);
  printf("Explanation: Compares addresses of first characters. Different "
         "arrays.\n\n");

  printf("str3 == str4: %d (pointer addresses)\n", str3 == str4);
  printf("Explanation: Compiler may optimize to use same literal.\n\n");

  printf("=== Summary ===\n");
  printf("- Use strcmp() to compare string content\n");
  printf("- == operator compares addresses, not content\n");
  printf("- String literals may share same memory location\n");

  return 0;
}