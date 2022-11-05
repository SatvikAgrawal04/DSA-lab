// WAP to arrange the elements of an array such that all even numbers are followed by all odd numbers using a single loop.

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

    int i = 0;
    int j = n-1;
    while (j>=i)
    {
        if(a[i]%2 != 0)
        {
            if (a[j]%2 == 0)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    
    return 0;
}