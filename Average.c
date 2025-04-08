#include <stdio.h>
#include <math.h>

int main()
{
    float marks, total = 0, average;
    int i;
    int passed = 1;

    printf("Enter marks obtained in 5 subjects:\n");

    for (i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks);

        while (marks < 0 || marks > 100)
        {
            printf("Invalid input, re-enter:\n");
            scanf("%f", &marks);
        }

        total += marks;

        if (marks < 40)
        {
            passed = 0;
        }
    }

    average = total / 5;

    printf("Total marks: %.2f\n", total);
    printf("Average marks: %.2f\n", average);

    if (passed)
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }

    return 0;
}