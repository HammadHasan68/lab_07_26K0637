#include <stdio.h>

int main(void) {
    int data[3][3], key[3][3], encrypted[3][3];
    int i, j;
    int highest, highRow = 0, highCol = 0;

    // Step 1: Read the data matrix
    printf("Enter the data matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Data for Row %d, Column %d: ", i + 1, j + 1);
            scanf("%d", &data[i][j]);
        }
    }

    // Step 2: Read the key matrix
    printf("\nEnter the key matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Key for Row %d, Column %d: ", i + 1, j + 1);
            scanf("%d", &key[i][j]);
        }
    }

    // Step 3: Apply the encryption rule to every cell
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            encrypted[i][j] = data[i][j] * key[i][j] + (i + j);
        }
    }

    // Step 4: Display the encrypted matrix
    printf("\nEncrypted Matrix:\n");
    printf("         Col1  Col2  Col3\n");
    for (i = 0; i < 3; i++) {
        printf("Row %-5d", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%-6d", encrypted[i][j]);
        }
        printf("\n");
    }

    // Step 5: Find the maximum value and its position
    highest = encrypted[0][0];          // start from a real value
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (encrypted[i][j] > highest) {
                highest = encrypted[i][j];
                highRow = i;
                highCol = j;
            }
        }
    }

    // Step 6: Final result
    printf("\nHighest Encrypted Value: %d\n", highest);
    printf("Position: Row %d, Column %d\n", highRow + 1, highCol + 1);

    return 0;
}