#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

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
void insert(struct node *last, int pos, int value)
{
    int i = 0;
    struct node *temp, *ptr = last, *prev = last;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    while (i < pos)
    {
        ptr = ptr->next;
        if (i)
            prev = prev->next;
        i++;
    }
    prev->next = temp;
    temp->next = ptr;
}

void display(struct node *head)
{
    head = head->next;
    struct node *ptr = head;
    do
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    int arr[] = {1, 3, 4, 5, 6};
    create(arr, 5);
    insert(first, 2, 2);
    display(first);
}