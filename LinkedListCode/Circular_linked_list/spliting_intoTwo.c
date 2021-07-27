#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *first2 = NULL;

void create(int a[], int n)
{
    struct node *ptr, *temp;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
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
    first = ptr;
}
void split(struct node *last)
{
    struct node *s = last->next, *f = last->next;

    // printf("%d", last->data);
    while (f != last && f->next != last)
    {
        s = s->next;
        f = f->next->next;
    }
    first2 = s->next;
    first = last->next;
    s->next = first;
    last->next = first2;
}

void display(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("NULL\n");
}
int main()
{
    int arr[] = {1, 3, 4, 5, 6, 7};
    create(arr, 6);
    split(first);
    display(first);
    display(first2);
}
