#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);


    int start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            start = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == y)
        {
            end = i;
            break;
        }
    }
    
    printf("minimum distance between %d and %d is %d", x, y, end - start);
    return 0;
}