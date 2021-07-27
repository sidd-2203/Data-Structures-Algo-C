#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

typedef struct q
{
    struct node *data;
    struct q *next;

} qq;
qq *f = NULL;
qq *r = NULL;

void enqueue(struct node *d)
{

    qq *temp = (qq *)malloc(sizeof(qq));
    if (!temp)
        printf("Queue full");
    temp->data = d;
    temp->next = NULL;
    if (f == NULL)
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
struct node *dequeue()
{
    struct node *x;
    if (f == NULL)
    {
        printf("Queue empty");
        x = NULL;
        return x;
    }
    qq *temp;
    temp = f;
    x = f->data;
    if (r == f)
        r = r->next;
    f = f->next;
    // x = temp->data;
    free(temp);
    return x;
}

void create_level(struct node *root)
{
    struct node *temp, *p;
    int x;
    printf("Enter the root value: (-1 f root is null) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        root = NULL;
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    root = temp;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    enqueue(temp);
    while (f != NULL)
    {
        p = dequeue();
        printf("Enter value of left child of %d (-1) if not present: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            p->left = temp;
            enqueue(temp);
        }

        printf("Enter value of right child of %d (-1) if not present: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            p->right = temp;
            enqueue(temp);
        }
    }
}
void display(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d is Left to %d and right is %d", root->left->data, root->data, root->right->data);
    display(root->left);
    display(root->right);
}

int main()
{
    struct node *root = NULL;
    create_level(root);
    display(root);
}