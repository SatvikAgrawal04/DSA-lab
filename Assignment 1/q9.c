#include <stdio.h>

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int lar = arr[0], sml = arr[0], s_lar = arr[0], s_sml = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > lar)
        {
            lar = arr[i];
        }
        if (arr[i] < sml)
        {
            sml = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > s_lar && arr[i] < lar)
        {
            s_lar = arr[i];
        }
        if (arr[i] < s_sml && arr[i] > sml)
        {
            s_sml = arr[i];
        }
        
    }

    printf("%d %d", s_lar, s_sml);

    return 0;
}