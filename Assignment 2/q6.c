#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int i = 0, j = n-1;
    while (i<j)
    {
        if (a[i] == 1)
        {
            if (a[j] == 0)
            {
                swap(&a[i], &a[j]);
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    
    
    return 0;
}