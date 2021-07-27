#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i, j, x;
};
struct sparse
{
    int n, m, num;
    struct element *e;
};

void add(struct sparse *s1, struct sparse *s2)
{
    if (s1->n == s2->n && s1->m == s2->m)
    {
        struct sparse *s3 = (struct sparse *)malloc(sizeof(struct sparse));
        s3->e = (struct element *)malloc(sizeof(struct element) * (s1->num + s2->num));
        s3->m = s1->m;
        s3->n = s1->n;

        int i = 0, j = 0, k = 0;
        while (i < s1->num && j < s2->num)
        {
            if (s1->e[i].i < s2->e[j].i)
            {
                s3->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].i > s2->e[j].i)
            {
                s3->e[k++] = s1->e[j];
            }
            else
            {
                if (s1->e[i].j < s2->e[j].j)
                {
                    s3->e[k++] = s1->e[i++];
                }
                else if (s1->e[i].j > s2->e[j].j)
                {
                    s3->e[k++] = s2->e[j++];
                }
                else
                {
                    s3->e[k] = s1->e[i++];
                    s3->e[k++].x += s2->e[j++].x;
                }
            }
        }
        s3->num = k;
    }
    else
        printf("Matrices cannot be added");
}