#include<stdio.h>

int main(){
    int totalRows = 5;
    int row, spaceCount, item;

    // Pattern 1: small star triangle
    printf("Pattern 1\n");
    for (row = 1; row <= totalRows; row++) {
        for (spaceCount = 1; spaceCount <= totalRows - row; spaceCount++)
            printf("  ");
        for (item = 1; item <= row; item++)
            printf("* ");
        printf("\n");
    }

    // Pattern 2: small digit triangle
    printf("\nPattern 2\n");
    for (row = 1; row <= totalRows; row++) {
        for (spaceCount = 1; spaceCount <= totalRows - row; spaceCount++)
            printf("  ");
        for (item = 1; item <= row; item++)
            printf("%d ", item);
        printf("\n");
    }

    // Pattern 3: small letter triangle
    printf("\nPattern 3\n");
    for (row = 1; row <= totalRows; row++) {
        for (spaceCount = 1; spaceCount <= totalRows - row; spaceCount++)
            printf("  ");
        for (item = 1; item <= row; item++)
            printf("%c ", 'A' + item - 1);
        printf("\n");
    }

    // Pattern 4: big star triangle
    printf("\nPattern 4\n");
    for (row = 1; row <= totalRows; row++) {
        for (spaceCount = 1; spaceCount <= totalRows - row; spaceCount++)
            printf("  ");
        for (item = 1; item <= 2 * row - 1; item++)
            printf("* ");
        printf("\n");
    }

    // Pattern 5: big digit triangle
    printf("\nPattern 5\n");
    for (row = 1; row <= totalRows; row++) {
        for (spaceCount = 1; spaceCount <= totalRows - row; spaceCount++)
            printf("  ");
        for (item = 1; item <= 2 * row - 1; item++)
            printf("%d ", item);
        printf("\n");
    }

    // Pattern 6: big letter triangle
    printf("\nPattern 6\n");
    for (row = 1; row <= totalRows; row++) {
        for (spaceCount = 1; spaceCount <= totalRows - row; spaceCount++)
            printf("  ");
        for (item = 1; item <= 2 * row - 1; item++)
            printf("%c ", 'A' + item - 1);
        printf("\n");
    }

    return 0;
}

