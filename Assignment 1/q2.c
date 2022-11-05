#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int temp = 0;

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    for (int i = 0; i < (n / 2); i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("\nReversed Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}