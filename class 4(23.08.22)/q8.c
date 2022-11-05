#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter the row : ");
    scanf("%d", &row);
    printf("Enter the column : ");
    scanf("%d", &col);
    int *arr = (int *)malloc(row * col * sizeof(int));
    int i, j, count = 0;
    printf("Enter the array : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", (arr + i * col + j));
        }
    }
    int flag = 0;
    // int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i < j)
            {
                if (*(arr + i * col + j) != 0)
                {
                    flag = -1;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("\nThe matrix is Lower Matrix");
    }
    else
    {
        printf("\nThe matrix is not Lower Matrix");
    }
    flag = 0;
    int c = col - 1;
    for (i = 0; i < row; i++)
    {
        for (j = c--; j < col; j++)
        {
            if (i > j)
            {
                if (*(arr + i * col + j) != 0)
                {
                    flag = -1;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("\nThe matrix is Upper Matrix");
    }
    else
    {
        printf("\nThe matrix is not Upper Matrix");
    }
    // printf("\n");
    flag = 1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i < j)
            {
                if (*(arr + i * col + j) != 0)
                {
                    flag = -1;
                }
            }
            else if (i > j)
            {
                if (*(arr + i * col + j) != 0)
                {
                    flag = -1;
                }
            }
        }
    }
    if (flag == 1)
    {
        printf("\nTri-diagonal Matrix");
    }
    else
    {
        printf("\nNot a tri-diagonal Matrix");
    }
    return 0;
}