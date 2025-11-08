#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
  char password[16];
  printf("Enter password: ");
  scanf("%[^\n]", password);

  bool uppercase=false, lowercase=false, digit=false, special=false, length=true;

  if(strlen(password) < 8) {
    printf("Password cannot be less than 8 characters!\n");
    length = false;
  } else if(strlen(password) > 15) {
    printf("Password cannot be greater than 15 characters!\n");
    length = false;
  }

  for(int i=0; i<strlen(password); i++) {
    int ch = (int)password[i];
    if(ch >= 65 && ch <= 90) {
      uppercase = true;
    }
    if(ch >= 97 && ch <= 122) {
      lowercase = true;
    }
    if(ch >= 48 && ch <= 57) {
      digit = true;
    }
    if((ch>=33 && ch<=38) || ch==42 || ch==64 || ch==94) {
      special = true;
    }
  }

  if(!uppercase) printf("uppercase character is missing!\n");
  if(!lowercase) printf("lowercase character is missing!\n");
  if(!digit) printf("digit is missing!\n");
  if(!special) printf("special character is missing!\n");
  if(uppercase && lowercase && digit && special && length)
    printf("Valid password!\n");
}