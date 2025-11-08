#include <stdio.h>

int main() {
    int arr[12];
    int window_size;
    int overall_max = -255;
    int best_window_start_index = -1;

    printf("Enter %d integers for the array:\n", 12);
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nEnter a window size (between 3 and 6): ");
        scanf("%d", &window_size);
        if (window_size < 3 || window_size > 6) {
            printf("Invalid size. Please try again.\n");
        }
    } while (window_size < 3 || window_size > 6);

    printf("\nMaximums of each window: ");

    for (int i = 0; i <= 12 - window_size; i++) {
        int current_window_max = arr[i];
        for (int j = i + 1; j < i + window_size; j++) {
            if (arr[j] > current_window_max) {
                current_window_max = arr[j];
            }
        }
        printf("%d ", current_window_max);

        if (current_window_max > overall_max) {
            overall_max = current_window_max;
            best_window_start_index = i;
        }
    }
    printf("\n");

    printf("\nOverall max window: [");
    for (int i = 0; i < window_size; i++) {
        printf("%d", arr[best_window_start_index + i]);
        if (i < window_size - 1) {
            printf(" ");
        }
    }
    printf("] with max value %d\n", overall_max);

    return 0;
}