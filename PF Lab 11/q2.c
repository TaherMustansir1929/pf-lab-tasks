#include<stdio.h>
#include <string.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    
    swap(&str[start], &str[end]);
    
    return reverseString(str, start + 1, end-1);
}

int main() {
    char str[] = "Hello World";
    
    reverseString(str, 0, strlen(str)-1 );
    
    printf("%s", str);
}