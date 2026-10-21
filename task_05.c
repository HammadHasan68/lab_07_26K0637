#include <stdio.h>

int main()
{
    int marks[2][3][3]; // marks[class][student][subject]
    int total[2][3];    // total[class][student]
    int classTopper[2]; // index of the topper in each class
    int i, j, k;
    int overallClass = 0, overallStudent = 0;

    // Step 1: Read marks for every class, student and subject
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("Class %d, Student %d, Subject %d: ", i + 1, j + 1, k + 1);
                scanf("%d", &marks[i][j][k]);
            }
        }
    }

    // Step 2: Total marks for each student (sum across the subject dimension)
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            total[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                total[i][j] += marks[i][j][k];
            }
        }
    }

    printf("\n========== Student Totals ==========\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Class %d, Student %d: %d marks\n", i + 1, j + 1, total[i][j]);
        }
    }

    // Step 3: Topper of each class (pick-a-max within each class)
    for (i = 0; i < 2; i++)
    {
        classTopper[i] = 0;
        for (j = 1; j < 3; j++)
        {
            if (total[i][j] > total[i][classTopper[i]])
            {
                classTopper[i] = j;
            }
        }
    }

    // Step 4: Overall topper across both classes
    for (i = 0; i < 2; i++)
    {
        int j = classTopper[i];
        if (total[i][j] > total[overallClass][overallStudent])
        {
            overallClass = i;
            overallStudent = j;
        }
    }

    // Step 5: Final results
    printf("\n========== Results ==========\n");
    for (i = 0; i < 2; i++)
    {
        int j = classTopper[i];
        printf("Top Performer of Class %d: Student %d with %d marks\n",
            i + 1, j + 1, total[i][j]);
    }

    printf("Overall Topper: Class %d, Student %d with %d marks\n",
        overallClass + 1, overallStudent + 1,
        total[overallClass][overallStudent]);

    return 0;
}