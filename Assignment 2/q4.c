#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter the no. of rows and columns: ");
    scanf("%d%d", &r, &c);
    int arr[r][c];
    printf("Enter elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < (c/2); j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][c-j-1];
            arr[i][c-j-1] = temp;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n"); 
    }
    
    return 0;
}