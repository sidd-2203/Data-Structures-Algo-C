#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int arr[], int n)
{
    struct node *ptr;
    for (int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
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
    ptr->next = first->next->next; // Created Loop
}

void removeLoop(struct node *head, struct node *s)
{
    struct node *ptr1, *ptr2;
    ptr1 = head;
    while (1)
    {
        ptr2 = s;
        while (ptr2->next != ptr1 && ptr2->next != s)
            ptr2 = ptr2->next;
        if (ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}
int detectLoop(struct node *head)
{
    struct node *f = head, *s = head;
    while (f && f->next && s)
    {
        f = f->next->next;
        s = s->next;
        if (f == s)
        {
            removeLoop(head, s);
            return 1;
        }
    }
    return 0;
}
void display(struct node *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    create(arr, 8);
    int i = detectLoop(first);
    // printf("%d", i);
    display(first);
}