#include<stdio.h>

int countDigits (int n) {
    if(n == 0)
        return 0;

    return  (n%10) + countDigits(n/10);
}

int main() {
    int n;
    scanf("%d", &n);

    int digits = countDigits(n);

    printf("sum Digits: %d", digits);
}