#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter rows and columns : ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    int i, j;
    printf("Input the array : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int k;
    for (k = 0; k < r; k++)
    {
        for (i = 0; i < c; i++)
        {
            for (j = (i + 1); j < c; ++j)
            {
                if (a[k][i] > a[k][j])
                {
                    int temp = a[k][i];
                    a[k][i] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
    for (j = 0; j < c; ++j)
    {
        for (i = 0; i < r; ++i)
        {
            for (k = i + 1; k < r; ++k)
            {
                if (a[i][j] < a[k][j])
                {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
    printf("Sorted array is : \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
