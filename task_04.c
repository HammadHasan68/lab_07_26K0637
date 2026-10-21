#include <stdio.h>

int main(void) {
    int temp[3][3][3];       // temp[x][y][z]
    double layerAvg[3];      // average of each layer (z = 0, 1, 2)
    int sum;
    int hottestLayer = 0;
    int maxTemp, maxX = 0, maxY = 0, maxZ = 0;
    int i, j, k;

    // Step 1: Read the temperature at every point
    printf("Enter the temperature (Celsius) for each point\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("x=%d, y=%d, z=%d: ", i + 1, j + 1, k + 1);
                scanf("%d", &temp[i][j][k]);
            }
        }
    }

    // Step 2: Average temperature of each layer (fixed z, all x and y)
    for (k = 0; k < 3; k++) {
        sum = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                sum += temp[i][j][k];
            }
        }
        layerAvg[k] = sum / 9.0;     // 9.0 avoids integer division
        printf("Average temperature of layer %d: %.2f\n", k + 1, layerAvg[k]);
    }

    // Step 3: Find the hottest layer
    for (k = 1; k < 3; k++) {
        if (layerAvg[k] > layerAvg[hottestLayer]) {
            hottestLayer = k;
        }
    }

    // Step 4: Find the point with the maximum temperature
    maxTemp = temp[0][0][0];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (temp[i][j][k] > maxTemp) {
                    maxTemp = temp[i][j][k];
                    maxX = i;
                    maxY = j;
                    maxZ = k;
                }
            }
        }
    }

    // Step 5: Final results
    printf("\n========== Results ==========\n");
    printf("Hottest layer: layer %d with average %.2f\n", hottestLayer + 1, layerAvg[hottestLayer]);
    printf("Maximum temperature: %d\n", maxTemp);
    printf("Coordinates of maximum: (%d, %d, %d)\n", maxX + 1, maxY + 1, maxZ + 1);

    return 0;
}