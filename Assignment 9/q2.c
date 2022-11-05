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

void binarySearch(int x, int a[], int n)
{
    int l = 0, r = n;
    sort(a, n);
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
        {
            printf("Found");
            return;
        }
        else if (a[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    printf("Not Found");
    return;
}

int main(int argc, char const *argv[])
{
    int a[] = {5, 2, 3, 1, 4, 9, 7, 8, 10};
    binarySearch(16, a, 5);
    return 0;
}
