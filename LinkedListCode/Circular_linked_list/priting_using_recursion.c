#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n)
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
    ptr->next = first;
}
void display(struct node *p)
{

    static int flag = 0;
    if (p != first || flag == 0)
    {
        flag = 1;
        printf("%d", p->data);
        display(p->next);
    }
    flag = 0;
}

int main()
{
    int arr[] = {5, 6, 7, 8, 1};
    create(arr, 5);
    display(first);
}