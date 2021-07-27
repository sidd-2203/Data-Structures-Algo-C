// There are two ways to improve linear search --> 1> Transposition    2-> move to head

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

struct node *transposed(struct node *head, int key)
{
    struct node *p, *q;
    q = NULL;
    p = head;
    if (head->data == key)
        return head;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            break;
        }
        q = p;
        p = p->next;
    }
    return p;
}

// int display_recursive(struct node *first)
// {
//     static int c = 0;
//     if (first != NULL)
//     {
//         c++;
//         // printf("%d", first->data);
//         display_recursive(first->next);
//     }
//     return c;
// }

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

int main()
{
    int arr[] = {5, 6, 7, 8, 1};
    create(arr, 5);
    first = transposed(first, 5);
    display(first);
}