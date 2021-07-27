#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

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
void distant(struct node *root, int k)
{
    if (k < 0 || !root)
        return;
    if (k == 0)
    {
        printf("%d\n", root->data);
        return;
    }
    distant(root->left, k - 1);
    distant(root->right, k - 1);
}
int main(int argc, char const *argv[])
{

    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    distant(root, 3);
    return 0;
}
