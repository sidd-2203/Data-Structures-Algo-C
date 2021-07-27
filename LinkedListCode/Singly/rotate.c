#include <stdlib.h>
#include <stdio.h>

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
void rotate(struct node *head, int k)
{
    int count = 1;
    while (count < k)
    {
        head = head->next;
        count++;
    }
    first = head->next;
    head->next = NULL;
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    create(arr, 6);
    rotate(first, 6);
    display(first);
}