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
void swap_noData(struct node *head, int k1, int k2)
{
    struct node *p = head, *q = head, *t1 = head, *t2 = head;
    while (head->next != NULL)
    {
        if (head->next->data == k1)
            t1 = head;
        if (head->next->data == k2)
            t2 = head;
        head = head->next;
    }
    p = t1->next;
    q = t2->next;

    t1->next = q;
    t2->next = p;
    t1 = q->next;
    q->next = p->next;
    p->next = t1;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main()
{
    int arr[] = {5, 6, 7, 8, 1};
    create(arr, 5);
    swap_noData(first, 1, 6);
    display(first);
}