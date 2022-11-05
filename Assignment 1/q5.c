#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int c, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &c, &b);


    int start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == c)
        {
            start = i;
        }
        if (a[i] = b)
        {
            end = i;
        }
    }
    
    printf("no of elements between %d and %d are %d", c, b, end - start);
    
    return 0;
}