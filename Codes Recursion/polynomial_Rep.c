#include <stdlib.h>
#include <stdio.h>

struct term
{
    int coeff;
    int expt;
};
struct poly
{
    int n;
    struct term *t;
};
int main()
{
    struct poly p;
    scanf("%d", &p.n);
    p.t = (struct term *)malloc(sizeof(struct term) * p.n);
    for (int i = 0; i < p.n; i++)
    {
        printf("enter the coefficient and power: ");
        scanf("%d%d", &p.t[i].coeff, &p.t[i].expt);
    }

    for (int i = 0; i < p.n; i++)
    {
        printf("%d x^%d +", p.t[i].coeff, p.t[i].expt);
    }

    return 0;
}