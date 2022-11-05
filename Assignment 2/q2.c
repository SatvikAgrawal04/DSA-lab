// WAP to find the largest number and counts the occurrence of the largest number in an array of n integers using a single loop.

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = a[0];
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= l)
        {
            if (a[i] == l)
                c++;
            else
            {
                l = a[i];
                c = 1;
            }
        }  
    }

    printf("largest no. is %d and it occurs %d times", l, c);
    
    return 0;
}