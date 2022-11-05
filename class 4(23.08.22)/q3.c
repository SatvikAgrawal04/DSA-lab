#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, column;
    printf("Enter row and column: ");
    scanf("%d%d", &row, &column);

    int *matrix;
    matrix = (int *)malloc((row * column) * sizeof(int));

    printf("Enter matrix:-\n");

    for (int i = 0; i < (row * column); i++)
        scanf("%d", (matrix + i));

    int c = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d\t", matrix[i * column + j]);
            if (matrix[i * column + j] == 0)
                c++;
        }
        printf("\n");
    }

    if (c <= (2.0 / 3) * (row * column))
        printf("Not a sparce matrix");

    else
        printf("Sparce matrix");

    return 0;
}