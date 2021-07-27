#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;
void *create(int a[], int n)
{
    struct node *ptr;
    for (int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        if (i == 0)
        {
            first = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
}
int display(struct node *first)
{
    static int c = 0;
    if (first != NULL)
    {
        c++;
        // printf("%d", first->data);
        display(first->next);
    }
    return c;
}

int main()
{
    int arr[] = {5, 6, 7, 8, 1, 8};
    create(arr, 6);
    printf("%d", display(first));
}