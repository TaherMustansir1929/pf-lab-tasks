#include <stdio.h>

int main() {
    int score;
    printf("Enter your score: ");
    scanf("%d", &score);

    if (score >= 5000)
    {
        printf("You are LEGENDARY!\n");
    } else if (score >= 3000) {
        printf("You are master!\n");
        printf("Legendary awaits you!\n");
    } else if (score >= 1500) {
        printf("You are an expert!\n");
        printf("Keey pushing, Master awaits you.\n");
    } else if (score >= 500) {
        printf("You are intermediate!\n");
        printf("A long journey awaits you!\n");
    } else if (score < 500 && score >= 0) {
        printf("you are a beginner!\n");
        printf("Get better noob!\n");
    }
     else {
        printf("Wrong input!\n");
    }
    
}