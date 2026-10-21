#include <stdio.h>

int main(void)
{
    int sales[4][5];
    int salesmanTotal[4] = {0};
    int productTotal[5] = {0};
    int bonusTotal[4];
    int bestProduct = 0;

    // Step 1: Input sales data
    printf("Enter the monthly sales (in rupees) for each salesman and product\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Salesman %d, Product %d: ", i + 1, j + 1);
            scanf("%d", &sales[i][j]);
        }
    }

    // Step 2: Total sales per salesman (traverse each row)
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            salesmanTotal[i] += sales[i][j];
        }
    }

    // Step 3: Total sales per product (traverse each column)
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            productTotal[j] += sales[i][j];
        }
    }

    // Step 4: Find the most expensive (highest revenue) product
    for (int j = 1; j < 5; j++)
    {
        if (productTotal[j] > productTotal[bestProduct])
        {
            bestProduct = j;
        }
    }

    // Step 5: Apply 10% bonus for salesmen above Rs. 10,000
    for (int i = 0; i < 4; i++)
    {
        if (salesmanTotal[i] > 10000)
        {
            bonusTotal[i] = salesmanTotal[i] + salesmanTotal[i] / 10; // 10% bonus
        }
        else
        {
            bonusTotal[i] = salesmanTotal[i];
        }
    }

    // Step 6: Final summary
    printf("\n========== Summary ==========\n");

    printf("\nTotal sales per salesman:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Salesman %d: Rs. %d\n", i + 1, salesmanTotal[i]);
    }

    printf("\nTotal sales per product:\n");
    for (int j = 0; j < 5; j++)
    {
        printf("Product %d: Rs. %d\n", j + 1, productTotal[j]);
    }

    printf("\nMost expensive product: Product %d (Rs. %d)\n",
        bestProduct + 1, productTotal[bestProduct]);

    printf("\nFinal amount after bonus:\n");
    for (int i = 0; i < 4; i++)
    {
        if (salesmanTotal[i] > 10000)
        {
            printf("Salesman %d: Rs. %d (10%% bonus applied)\n", i + 1, bonusTotal[i]);
        }
        else
        {
            printf("Salesman %d: Rs. %d (no bonus)\n", i + 1, bonusTotal[i]);
        }
    }

    return 0;
}