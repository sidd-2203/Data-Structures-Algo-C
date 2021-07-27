#include <stdlib.h>
#include <stdio.h>

struct node
{
    void *data;
    struct node *next;
} *first = NULL;

void create(int arr[], int n)
{
    struct node *temp, *ptr;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        // temp->data = malloc(sizeof(int));
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
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", (head->data));
        head = head->next;
    }
    printf("NULL");
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
}