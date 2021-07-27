#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;

void create(int arr[], int n)
{
    struct node *temp, *ptr;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        if (i == 0)
        {
            temp->prev = NULL;
            first = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            temp->prev = ptr;
            ptr = ptr->next;
        }
    }
}

void display(struct node *head)
{

    while (head->next)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("%d->Null\n", head->data);
    while (head)
    {
        printf("%d ->", head->data);
        head = head->prev;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
}
