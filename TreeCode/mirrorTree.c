#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left, *right;
    int data;
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
struct node *mirror(struct node *root)
{
    if (!root || (!root->right && !root->left))
        return root;

    struct node *temp = root->right;
    root->right = mirror(root->left);
    root->left = mirror(temp);
    return root;
}
void InOrder(struct node *root)
{
    if (root)
    {
        InOrder(root->left);
        printf("%d  ", root->data);
        InOrder(root->right);
    }
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {1, 3, -1, -1, 2, 5, -1, -1, 4, -1, -1};
    root = create_tree(arr);
    InOrder(root);
    root = mirror(root);
    InOrder(root);
    return 0;
}