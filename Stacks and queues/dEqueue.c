#include <stdio.h>
#include <stdlib.h>

typedef struct dq
{
    int data;
    struct dq *next;

} dq;
dq *f = NULL, *r = NULL;
void insertFront(int data)
{
    dq *temp = (dq *)malloc(sizeof(dq));
    if (temp == NULL)
        printf("Queue is full");
    else
    {
        temp->data = data;
        if (!f)
        {
            f = temp;
            r = temp;
        }
        else
        {
            temp->next = f;
            f = temp;
        }
    }
}
void insertRear(int data)
{
    dq *temp = (dq *)malloc(sizeof(dq));
    if (temp == NULL)
        printf("Queue is full");
    else
    {
        temp->data = data;
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
}
int deleteFront()
{
    int x = -1;
    dq *temp = NULL;
    if (!f)
        printf("empty");
    else
    {
        temp = f;
        f = f->next;
        x = temp->data;
        free(temp);
    }
    return x;
}
int deleterear()
{
    int x = -1;
    dq *qq = NULL;
    qq = f;
    if (!f)
        printf("Empty queue");
    else
    {
        while (qq->next != r && qq->next != NULL)
        {
            qq = qq->next;
        }
    }
    x = r->data;
    free(qq);
    return x;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        if (i & 1)
            insertFront(arr[i]);
        else
            insertRear(arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d", deleteFront());
    }
    return 0;
}