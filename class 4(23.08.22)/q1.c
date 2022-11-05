#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{
    int power;
    float coeff;
    float x;
};

int main()
{
    struct polynomial *p1;
    p1 = (struct polynomial *)malloc(sizeof(struct polynomial));

    printf("Enter the values int the order(power, coeff, x):\n");
    scanf("%d%f%f", &p1->power, &p1->coeff, &p1->x);

    printf("Polynomial is:\n");
    for (int i = p1->power; i >= 0; i--)
    {
        if (i > 0)
        {
            printf("%.1f*%.1f ^ %d + ", p1->coeff, p1->x, i);
        }
        else
        {
            printf("%.1f", p1->coeff);
        }
    }

    float ans = 0;

    for (int i = p1->power; i >= 0; i--)
    {
        ans = ans + p1->coeff * pow(p1->x, i);
    }
    printf("\nAns: %.2f", ans);

    return 0;
}