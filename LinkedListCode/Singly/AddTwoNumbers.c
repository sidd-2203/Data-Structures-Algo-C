#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

struct node *create(int n)
{
    struct node *head = NULL, *ptr;
    int dig = 0;
    while (n != 0)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n % 10;
        if (!dig)
        {
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
        n /= 10;
        dig++;
    }
    return head;
}

struct node *add(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1, *ptr2 = head2;
    int c = 0;
    while (ptr1->next && ptr2)
    {
        ptr1->data += ptr2->data + c;
        if (ptr1->data > 9)
        {
            c = 1;
            ptr1->data -= 10;
        }
        else
            c = 0;
        ptr1 = ptr1->next;
        ptr2 - ptr2->next;
    }
    if (c && !ptr1 && !ptr2)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = NULL;
        ptr1->next = temp;
    }
    else if (!ptr1->next && ptr2)
    {
        ptr1->data += c + ptr2->data;
    }
    else
    {
        ptr1->next = ptr2;
        ptr1->next->data += c;
    }
}