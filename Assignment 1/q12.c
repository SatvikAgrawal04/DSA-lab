#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int temp[n];
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) < n && (i - 1) >= 0)
            temp[i] = arr[i - 1] * arr[i + 1];
        else
            temp[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}