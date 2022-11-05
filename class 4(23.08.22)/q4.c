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

    printf("Original Matrix\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d\t", matrix[i * column + j]);
        }
        printf("\n");
    }

    printf("Transpose Matrix\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d\t", matrix[j * column + i]);
        }
        printf("\n");
    }

    return 0;
}