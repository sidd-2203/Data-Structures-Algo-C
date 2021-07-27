#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

struct node *create(int a[], int n)
{
    struct node *ptr, *head = NULL;
    for (int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        if (i == 0)
        {
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
    return head;
}
struct node *merge_sorted(struct node *head1, struct node *head2)
{
    struct node *t, *last;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data)
    {
        t = head1;
        last = head1;
        head1 = head1->next;
        last->next = NULL;
    }
    else
    {
        t = head2;
        last = head2;
        head2 = head2->next;
        last->next = NULL;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            last->next = head1;
            last = last->next;
            head1 = head1->next;
            last->next = NULL;
        }
        else
        {
            last->next = head2;
            last = last->next;
            head2 = head2->next;
            last->next = NULL;
        }
    }
    if (head1 != NULL)
        last->next = head1;
    else if (head2 != NULL)
        last->next = head2;

    return t;
}
struct node *divide(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct node *f = head, *s = head;

    while (f->next != NULL && f->next->next != NULL)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}

struct node *MergeSort(struct node *head)
{
    struct node *a, *b;
    if (head == NULL || head->next == NULL)
        return head;
    struct node *mid = divide(head);
    struct node *nHead = mid->next;
    mid->next = NULL;
    a = MergeSort(head);
    b = MergeSort(nHead);
    first = merge_sorted(a, b);
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
    struct node *h1, *h2, *t;
    int arr2[] = {21, -1, 16, 25, 29, 2};
    h1 = create(arr2, 6);
    MergeSort(h1);
    display(first);
}