#include <stdio.h>

void printMemoryBytes(void *ptr, int size) {
  unsigned char *byte_ptr = (unsigned char *)ptr;
  printf("Memory content (hex): ");
  for (int i = 0; i < size; i++) {
    printf("%02X ", byte_ptr[i]);
  }
  printf("\n");
}

int sampleFunc(int x) { return x * 2; }

int main() {
  int num = 305419896;
  int *ptr_int = &num;
  int arr[5] = {1, 2, 3, 4, 5};
  int (*ptr_arr)[5] = &arr;
  int (*func_ptr)(int) = sampleFunc;

  printf("=== Variable Addresses and Sizes ===\n\n");

  printf("Integer:\n");
  printf("Address: %p, Size: %lu bytes\n", (void *)&num, sizeof(num));
  printMemoryBytes(&num, sizeof(num));
  printf("\n");

  printf("Pointer to int:\n");
  printf("Address: %p, Size: %lu bytes\n", (void *)&ptr_int, sizeof(ptr_int));
  printMemoryBytes(&ptr_int, sizeof(ptr_int));
  printf("\n");

  printf("Array:\n");
  printf("Address: %p, Size: %lu bytes\n", (void *)arr, sizeof(arr));
  printMemoryBytes(arr, sizeof(arr));
  printf("\n");

  printf("Pointer to array:\n");
  printf("Address: %p, Size: %lu bytes\n", (void *)&ptr_arr, sizeof(ptr_arr));
  printMemoryBytes(&ptr_arr, sizeof(ptr_arr));
  printf("\n");

  printf("Function pointer:\n");
  printf("Address: %p, Size: %lu bytes\n", (void *)&func_ptr, sizeof(func_ptr));
  printMemoryBytes(&func_ptr, sizeof(func_ptr));
  printf("\n");

  printf("=== Observations ===\n");
  printf("1. Pointers are %lu bytes (system dependent)\n", sizeof(void *));
  printf("2. Arrays stored contiguously in memory\n");
  printf("3. Integers typically stored in little-endian format\n");
  printf("4. Memory alignment may add padding between variables\n");

  return 0;
}