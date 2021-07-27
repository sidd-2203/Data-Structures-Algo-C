#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root1 = NULL;
struct node *root2 = NULL;

struct node *create(int a[], int n)
{
    struct node *ptr, *head;
    for (int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->link = NULL;
        if (i == 0)
        {
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->link = temp;
            ptr = ptr->link;
        }
    }
    return head;
}
struct node *merge(struct node *a, struct node *b)
{
    struct node *res = NULL;
    if (!a)
        res = b;
    else if (!b)
        res = a;
    else
    {
        while (a != NULL || b != NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            if (a == NULL && b != NULL)
            {
                temp->data = b->data;
                b = b->link;
            }
            else if (a != NULL && b == NULL)
            {
                temp->data = a->data;
                a = a->link;
            }
            else if (a->data <= b->data)
            {
                temp->data = a->data;
                temp->link = NULL;
                a = a->link;
            }
            else
            {
                temp->data = b->data;
                temp->link = NULL;
                b = b->link;
            }
            if (res == NULL)
                res = temp;
            else
            {
                struct node *prev;
                prev = res;
                while (prev->link != NULL)
                    prev = prev->link;
                prev->link = temp;
            }
        }
    }
    return res;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->link;
    }
    printf("NULL\n");
}

int main(void)
{
    struct node *head;
    int arr2[] = {1, 3, 5};
    int arr[] = {2, 4, 6};
    root1 = create(arr, 3);
    root2 = create(arr2, 3);
    head = merge(root1, root2);
    printList(head);
}