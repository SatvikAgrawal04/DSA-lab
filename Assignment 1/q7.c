#include <stdio.h>

void non_zero(int row, int coloumn, int a[row][coloumn])
{
    int count = 0;
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < coloumn; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("Number of non-zero elements are : %d\n", count);
}

void above_leading_diagonal(int row, int coloumn, int a[row][coloumn])
{
    int sum = 0;
    int i, j;
    for (i = 0; i < row - 1; i++)
    {
        for (j = i + 1; j < coloumn; j++)
        {
            sum += a[i][j];
        }
    }
    printf("Sum of the elements above the leading diagonal are : %d\n", sum);
}

void minor_diagonal_elements(int row, int coloumn, int a[row][coloumn])
{
    printf("Elements below minor diagonal : \n");
    int i, j;
    for (i = 1; i < row; i++)
    {
        printf("\t");
        for (j = 0; j < i; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void product_of_diagonal_elements(int row, int coloumn, int a[row][coloumn])
{
    int product = 1;
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < coloumn; j++)
        {
            if (i == j)
            {
                product = product * a[i][j];
            }
        }
    }
    printf("Product of the diagonal elements : %d", product);
}

int main()
{
    int row, coloumn;
    printf("Enter row and coloumn : ");
    scanf("%d%d", &row, &coloumn);
    int a[row][coloumn];
    int i, j;
    printf("Enter the array : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < coloumn; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    non_zero(row, coloumn, a);

    above_leading_diagonal(row, coloumn, a);

    minor_diagonal_elements(row, coloumn, a);

    product_of_diagonal_elements(row, coloumn, a);

    return 0;
}