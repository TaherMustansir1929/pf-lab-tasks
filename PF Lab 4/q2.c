#include <stdio.h>
int main() 
{
    int c, f;
    printf("Enter temperature in celsius: ");
    scanf("%d", &c);
    f = (c*(9/5))+32;
    if(f<65 || f>80) {
        printf("Weather is not ideal.");
    } else {
        printf("Perfect Weather!");
    }
}