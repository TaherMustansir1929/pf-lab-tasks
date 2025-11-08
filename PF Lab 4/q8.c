#include <stdio.h>

int main() {
    int marks;
    char grade;

    printf("Enter marks (0-100): ");
    scanf("%d", &marks);

    if (marks <= 100 && marks >= 90) {
        grade = 'A';
        printf("Grade: %c\n", grade);
    } else if (marks < 90 && marks >= 80)
    {
        grade = 'B';
        printf("Grade: %c\n", grade);
    } else if (marks < 80 && marks >= 70)
    {
        grade = 'C';
        printf("Grade: %c\n", grade);
    } else if (marks < 70 && marks >= 60)
    {
        grade = 'D';
        printf("Grade: %c\n", grade);
    } else {
        grade = 'F';
        printf("Grade: %c\n", grade);
    }

    switch (grade)
    {
    case 'A':
        printf("Performance: You are a topper\n");
        printf("Recommendation: Touch some grass\n");
        break;
    case 'B':
        printf("Performance: Good work! You are doing well\n");
        printf("Recommendation:A little more effort and you are will be a topper\n");
        break;
    case 'C':
        printf("Performance: Good try\n");
        printf("Recommendation: Need to put some extra time into studies and you will be good to go\n");
        break;
    case 'D':
        printf("Performance: Needs Improvement\n");
        printf("Recommendation: You need to put extra efforts\n");
        break;
    case 'F':
        printf("Performance: Get better\n");
        printf("Recommendation: There is no saving you!\n");
        break;
    
    default:
    printf("Invalid input");
        break;
    }
    
    
    
}