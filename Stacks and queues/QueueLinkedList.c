#include <stdio.h>
#include <stdlib.h>

typedef struct q
{
    int data;
    struct q *next;

} qq;
qq *f = NULL;
qq *r = NULL;

void enqueue(int d)
{
    qq *temp = NULL;
    temp = (qq *)malloc(sizeof(qq));
    if (!temp)
        printf("Queue full");
    temp->data = d;
    temp->next = NULL;
    if (!f)
    {
        f = temp;
        r = temp;
    }
    else
    {
        r->next = temp;
        r = r->next;
    }
}
int dequeue()
{
    if (!f)
    {
        printf("Queue empty");
    }
    qq *temp;
    temp = f;
    f = f->next;
    int x = temp->data;
    free(temp);
    return x;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        enqueue(arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d-> ", dequeue());
    }
}
