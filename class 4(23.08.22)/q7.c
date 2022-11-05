#include <stdio.h>
#include <stdlib.h>

int freq(int arr[], int n, int a)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *arr0 = (int *)malloc(n * sizeof(int));

    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                arr0[j] = 0;
            }
        }
        if (arr0[i] != 0)
        {
            arr0[i] = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr0 + i));
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Freq of %d : %d\n", arr[i], freq(arr, n, arr[i]));
    // }

    return 0;
}