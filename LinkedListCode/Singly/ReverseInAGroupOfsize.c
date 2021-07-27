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
void reverse(struct node *head, int k)
{
    int count = 0;
    struct node *p = head, *q = NULL, *temp = head->next;
    while (p != NULL && count < k)
    {
        count++;
        p->next = q;
        q = p;
        p = temp;
        if (temp != NULL)
            temp = temp->next;
    }
    if (p != NULL)
        head->next = p;
    first = q;
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
    reverse(first, 1);
    display(first);
}