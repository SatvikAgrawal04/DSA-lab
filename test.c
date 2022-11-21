#include <stdio.h>

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int binarySearch(int x, int a[], int l, int r, int n)
{
    sort(a, n);
    if (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
        {
            return 1;
        }
        else if (a[m] < x)
        {
            binarySearch(x, a, (m + 1), r, n);
        }

        binarySearch(x, a, l, (m - 1), n);
    }
    return -1;
}

int main()
{
    printf("Enter no. of elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter element to search: ");
    scanf("%d", &x);
    int f = binarySearch(x, arr, 0, (n - 1), n);
    if (f = 1)
    {
        printf("Found");
    }
    else
    {
        printf("Not found");
    }
    return 0;
}