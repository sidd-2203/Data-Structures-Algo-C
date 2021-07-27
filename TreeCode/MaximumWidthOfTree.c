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
int size_que()
{
    int c = 0;
    qq *p = f;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}
int calWidth(struct node *root)
{
    if (!root)
        return 0;
    int c = 0, ans = 0;
    struct node *p, *q;
    p = root;
    enqueue(root);
    while (f)
    {
        c = size_que();
        if (c > ans)
            ans = c;
        while (c--)
        {
            p = dequeue();
            if (p->left)
                enqueue(p->left);
            if (p->right)
                enqueue(p->right);
        }
    }
    if (c > ans)
        ans = c;
    return ans;
}
struct node *create_tree(int arr[])
{
    static int a = 0;
    struct node *temp;
    int x;
    temp = (struct node *)malloc(sizeof(struct node));
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
/* MANAN JAIN INSTRUCTION 
int maxWidth(struct node *root)
{
    int i = 0, j = 2;
    struct node *arr[1000] = {NULL};
    arr[0] = root;
    arr[1] = NULL;
    while (i != j)
    {
        if (arr[i] == NULL)
        {
            i++;
            arr[j++] = NULL;
        }
        struct node *temp = arr[i];
        if (temp->left)
        {
            arr[j] = temp->left;
            j++;
        }
        if (temp->right)
        {
            arr[j] = temp->right;
            j++;
        }
        i++;
    }
    // Loop it and get max distance between two nulls
}
*/

int main(int argc, char const *argv[])
{

    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    printf("Max Width is %d ", calWidth(root));
    return 0;
}
