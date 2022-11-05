#include <stdio.h>
#include <stdlib.h>
int max(int *a, int n)
{
    static int i = 0, t, m = 0;
    if (i == n)
    {
        return m;
    }
    t = a[i];
    m = (m > t) ? m : t;
    i++;
    max(a, n);
}
int main()
{
    int n, m, i;
    printf("enter number of element:");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("enter %d elements:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    m = max(a, n);
    printf("largest element is %d", m);
    return 0;
}