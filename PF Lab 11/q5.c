#include <stdio.h>
#include <math.h>

#define DISKS 4
#define MAX_MOVES 16

typedef struct {
    int n;
    char src;
    char dest;
} Move;

Move moves[MAX_MOVES];
int count = 0;

void towerOfHanoi(int n, char src, char hlp, char dest) {
    if (n == 0) {
        return;
    }
    
    towerOfHanoi(n - 1, src, dest, hlp);
    
    
    moves[count].n = n;
    moves[count].src = src;
    moves[count].dest = dest;
    
    printf("Move %d: n = %d : %c -> %c\n", count + 1, n, src, dest);
    
    count++;
    
    
    towerOfHanoi(n - 1, hlp, src, dest);
}

void displaySpecificMove(int moveNum) {
    if (moveNum > 0 && moveNum <= count) {
        Move m = moves[moveNum - 1];
        printf("\nDetails of Move %d:\n", moveNum);
        printf("  n: %d\n", m.n);
        printf("  src Rod: %c\n", m.src);
        printf("  dest Rod: %c\n", m.dest);
    } else {
        printf("\nInvalid move number. Please enter a number between 1 and %d.\n", count);
    }
}

int main() {
    int nums = DISKS;
    int choice;

    printf("======================================\n");
    printf("  TOWER OF HANOI (N=%d) WITH TRACKING\n", nums);
    printf("======================================\n");
    printf("Executing moves:\n");

    towerOfHanoi(nums, 'A', 'B', 'C');
    
    printf("\n======================================\n");
    printf("  Total Moves Calculated: %d\n", count);
    printf("  Expected Moves: %d\n", (int)pow(2, nums) - 1);
    printf("======================================\n");

    while (1) {
        printf("\nEnter move number to view details (1 to %d, or 0 to exit): ", count);
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 0) {
            printf("Exiting move tracking.\n");
            break;
        }

        displaySpecificMove(choice);
    }

    return 0;
}