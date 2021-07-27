#include <stdlib.h>
#include <stdio.h>

struct node
{
    struct node *next, *random;
    int data;
};
struct node *first = NULL;
void create(int arr[], int n)
{
    int x;
    struct node *ptr;
    for (int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->random = NULL;
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
    struct node *curr = first;
    for (int i = 0; i < n; i++)
    {
        printf("%d randomly pointed to (-1 for null) ->", curr->data);
        scanf("%d", &x);
        if (x == -1)
        {
            curr->random = NULL;
        }
        else
        {
            struct node *temp = first;
            while (temp)
            {
                if (temp->data == x)
                {
                    curr->random = temp;
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Dont to bullshit here..... we are pointing it to null\n");
                curr->random = NULL;
            }
        }
        curr = curr->next;
    }
}

struct node *clone()
{

    struct node *new_first = NULL, *p = first, *q = NULL, *r = NULL;
    while (p)
    {
        q = (struct node *)malloc(sizeof(struct node));
        q->data = p->data;
        q->next = q->random = NULL;
        if (!new_first)
        {
            new_first = q;
            r = q;
        }
        else
        {
            r->next = q;
            r = r->next;
        }
        p = p->next;
    }
    p = first;
    q = NULL;
    r = new_first;
    while (p)
    {
        q = p->next;
        p->next = r;
        r->random = p;
        r = r->next;
        p = q;
    }
    p = new_first;
    q = r = NULL;

    while (p)
    {
        if (!p->random->random)
            p->random = NULL;
        else
            p->random = p->random->random->next;
        p = p->next;
    }

    return new_first;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp)
    {
        printf("%d data ", temp->data);
        if (!temp->random)
            printf("Random is NULL\n");
        else
            printf("%d is random\n ", temp->random->data);

        temp = temp->next;
    }
}

int main()
{
    first = NULL;
    int arr[] = {1, 2, 3, 4};
    create(arr, 4);
    struct node *newfirst = clone();
    display(newfirst);
}