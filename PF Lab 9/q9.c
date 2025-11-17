#include <stdio.h>

typedef void *(*state_func)(int);

void *stateA(int input);
void *stateB(int input);
void *stateC(int input);
void *stateD(int input);

int current_value = 0;

void *stateA(int input) {
  printf("State A: Input = %d\n", input);
  current_value = input;
  if (input > 5) {
    printf("Going to State B\n");
    return stateB;
  } else {
    printf("Going to State C\n");
    return stateC;
  }
}

void *stateB(int input) {
  printf("State B: Multiply by 2\n");
  current_value = current_value * 2;
  printf("Going to State D\n");
  return stateD;
}

void *stateC(int input) {
  printf("State C: Add 10\n");
  current_value = current_value + 10;
  printf("Going to State D\n");
  return stateD;
}

void *stateD(int input) {
  printf("State D: Final result = %d\n", current_value);
  return NULL;
}

int main() {
  int input;
  printf("Enter a number: ");
  scanf("%d", &input);

  state_func current_state = stateA;

  while (current_state != NULL) {
    current_state = (state_func)current_state(input);
  }

  return 0;
}