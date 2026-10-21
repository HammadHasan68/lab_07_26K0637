#include <stdio.h>

int main(void)
{
    int classes, students, subjects, marks;
    int totalMarks, average, failed;
    int classTotal, classAvg;
    int schoolTotal = 0, schoolAvg, schoolStudents = 0;
    int i, j, k;

    printf("Enter total number of classes in the school: ");
    scanf("%d", &classes);

    for (i = 1; i <= classes; i++)
    {
        printf("\nEnter number of students in Class %d: ", i);
        scanf("%d", &students);

        classTotal = 0; // reset the class total for this class

        for (j = 1; j <= students; j++)
        {
            printf("\nEnter number of subjects for Student %d: ", j);
            scanf("%d", &subjects);

            totalMarks = 0;
            failed = 0; // 0 = pass, 1 = fail

            for (k = 1; k <= subjects; k++)
            {
                printf("Enter marks for Subject %d: ", k);
                scanf("%d", &marks);

                totalMarks = totalMarks + marks;
                if (marks < 40)
                {
                    failed = 1;
                }
            }

            average = totalMarks / subjects;

            if (failed == 1)
            {
                printf("Class %d, Student %d: Total Marks = %d, Average = %d, Result = Fail\n",
                    i, j, totalMarks, average);
            }
            else
            {
                printf("Class %d, Student %d: Total Marks = %d, Average = %d, Result = Pass\n",
                    i, j, totalMarks, average);
            }

            classTotal = classTotal + totalMarks;
            schoolStudents++;
        }

        classAvg = classTotal / students;
        printf("\nClass %d: Total marks of all students = %d, Class average = %d\n",
            i, classTotal, classAvg);

        schoolTotal = schoolTotal + classTotal;
    }

    schoolAvg = schoolTotal / schoolStudents;
    printf("\nTotal marks of all students across all classes = %d\n", schoolTotal);
    printf("Overall school average = %d\n", schoolAvg);

    return 0;
}