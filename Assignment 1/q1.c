#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int s = a[0], l = a[0];

    for (int i = 0; i < n; i++)
    {
        if (a[i] < s)
        {
            s = a[i];
        }
        if (a[i] > l)
        {
            l = a[i];
        }
    }

    printf("smallest is %d and largest is %d", s, l);
    

    return 0;
}