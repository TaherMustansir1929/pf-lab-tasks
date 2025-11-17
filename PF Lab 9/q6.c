#include <stdio.h>
#include <string.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div_op(int a, int b) { return b != 0 ? a / b : 0; }

int (*getOperation(char *cmd))(int, int) {
  if (strcmp(cmd, "add") == 0)
    return add;
  if (strcmp(cmd, "sub") == 0)
    return sub;
  if (strcmp(cmd, "mul") == 0)
    return mul;
  if (strcmp(cmd, "div") == 0)
    return div_op;
  return NULL;
}

int main() {
  char command[10];
  int a = 10, b = 5;

  printf("Enter command (add/sub/mul/div): ");
  scanf("%s", command);

  int (*operation)(int, int) = getOperation(command);

  if (operation != NULL) {
    int result = operation(a, b);
    printf("Result of %d %s %d = %d\n", a, command, b, result);
  } else {
    printf("Invalid command!\n");
  }

  return 0;
}