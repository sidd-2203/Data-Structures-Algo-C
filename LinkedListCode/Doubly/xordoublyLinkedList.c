#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *npx;
} *head = NULL, *tail = NULL;

struct node * xor (struct node * a, struct node *b)
{
    return (struct node *)(((unsigned)(a)) ^ ((unsigned)(b)));
};

void create(int arr[], int n)
{
    struct node *temp, *next;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->npx = xor(tail, NULL);
        if (head = NULL)
        {
            head = temp;
        }
        if (tail != NULL)
        {
            next = xor(tail->npx, NULL);
            tail->npx = xor(temp, next);
        }
        tail = temp;
    }
}
void print()
{
    struct node *curr = head, *pre = NULL, *next;
    while (curr)
    {
        printf("%d", curr->data);
        next = xor(pre, curr->npx);
        pre = curr;
        curr = next;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    create(arr, 4);
    print();
}