#include <stdio.h>

int main() {
    int seats[10][4] = {0};
    int seatnum, row, col, reserved = 0;

    printf("How many seats do you want to reserve? ");
    scanf("%d", &seatnum);

    while (reserved < seatnum) {
        printf("\nEnter row number (1-10): ");
        scanf("%d", &row);
        printf("Enter seat number (1-4): ");
        scanf("%d", &col);

        if (row < 1 || row > 10 || col < 1 || col > 4) {
            printf("Invalid row or seat. Enter row 1-10 and seat 1-4.\n");
        }
        else if (seats[row - 1][col - 1] == 1) {
            printf("Seat already booked\n");
        }
        else {
            seats[row - 1][col - 1] = 1;
            reserved++;
            printf("Seat reserved successfully.\n");
        }
    }

    printf("\n========== Seating Arrangement ==========\n");
    printf("        Seat1 Seat2 Seat3 Seat4\n");
    for (int i = 0; i < 10; i++) {
        printf("Row %2d:", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%6d", seats[i][j]);
        }
        printf("\n");
    }

    int fullyBooked = 0;
    printf("\nFully booked rows: ");
    for (int i = 0; i < 10; i++) {
        int full = 1;
        for (int j = 0; j < 4; j++) {
            if (seats[i][j] == 0) {
                full = 0;
            }
        }
        if (full) {
            fullyBooked++;
            printf("%d ", i + 1);
        }
    }
    if (fullyBooked == 0) {
        printf("None");
    }

    printf("\n\nTotal number of fully booked rows: %d\n", fullyBooked);

    return 0;
}