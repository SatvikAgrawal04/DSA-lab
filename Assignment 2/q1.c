#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nThe %d smallest is %d and %d largest is %d", k, a[k - 1], k, a[n - k]);

    return 0;
}