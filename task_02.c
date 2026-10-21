#include <stdio.h>

int main(void) {
    int grid[3][3];
    int seen[10] = {0};   // seen[n] becomes 1 once the number n has appeared
    int valid = 1;        // 1 = valid, 0 = invalid

    // Read the 3x3 box
    printf("Enter the 3x3 Sudoku box (0 for empty, 1-9 for filled cells)\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &grid[i][j]);
        }
    }

    // Check range and duplicates in one pass
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int value = grid[i][j];

            if (value == 0) {
                continue;               // empty cell, ignore it
            }
            if (value < 1 || value > 9) {
                valid = 0;              // out of range
            } else if (seen[value]) {
                valid = 0;              // duplicate
            } else {
                seen[value] = 1;        // record that this number has appeared
            }
        }
    }

    if (valid) {
        printf("\nValid Grid\n");
    } else {
        printf("\nInvalid Grid\n");
    }

    return 0;
}