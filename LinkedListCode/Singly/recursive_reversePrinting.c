#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *first)
{
    if (first != NULL)
    {
        display(first->next);
        printf("%d", first->data);
    }
}