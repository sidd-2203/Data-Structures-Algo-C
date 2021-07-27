#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *name;
    struct node *next;
};
struct queue
{
    struct node *front;
    struct node *rear;
    int size;
};
void insert(struct queue *n)
{
    printf("enter the name\n");
    char name[50];
    scanf("%s", name);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->name = (char *)malloc(strlen(name) + 1);
    strcpy(temp->name, name);
    temp->next = n->front;
    if (n->front == NULL)
    {
        n->front = temp;
        n->rear = temp;
    }
    else
    {
        n->rear->next = temp;
        n->rear = temp;
    }
    n->size++;
}

void delete (struct queue *n)
{
    int pos, i = 1;
    struct node *temp = NULL, *temp2 = NULL;
    printf("Enter the pos to delete: ");
    scanf("%d", &pos);
    if (n->size == 0)
    {
        printf("queue is emmpty\n");
        return;
    }
    else if (pos == 1)
    {
        temp = n->front;
        n->size--;
        n->front = n->front->next;
        n->rear->next = n->front;
        free(temp);
    }
    else
    {
        temp = n->front;
        while (i < pos - 1 && i <= n->size)
        {
            temp = temp->next;
            i++;
        }
        if (i > n->size)
        {
            printf("invalid position\n");
            return;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    n->size--;
}

void display(struct queue *q)
{
    struct node *temp = q->front;
    while (temp != NULL)
    {
        printf("%s", temp->name);
        temp = temp->next;
    }
}
void peek(struct queue *q)
{
    int pos, i = 1;
    printf("Enter the position to peak: ");
    scanf("%d", &pos);
    if (pos > q->size)
    {
        printf("invalid position\n");
        return;
    }
    struct node *temp = q->front;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    printf("%s", temp->name);
}
int instructions()
{
    printf("Enter the choice\n");
    printf("Enter 1 for Insert(enqueue)in the list\n");
    printf("Enter 2 for Delete(DEqueue)in the list\n");
    printf("Enter 3 for Peeking in the list\n");
    printf("Enter 4 for Display the list\n");
    printf("Enter 5 to quit\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

int main()
{
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
    do
    {
        int choice = instructions();
        switch (choice)
        {
        case 1:
            insert(&q);
            break;
        case 2:
            delete (&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            display(&q);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("You have entered wrong choice reEnter: \n");
            break;
        }
    } while (1);

    return 0;
}