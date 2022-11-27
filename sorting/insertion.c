#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] < arr[n - 1 - i])
            {
                /* code */
            }
        }
    }

    return 0;
}
