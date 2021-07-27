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
int isSame(struct node *a, struct node *b)
{
    if (!a && !b)
        return 1;
    return (a && b && isSame(a->left, b->left) && isSame(a->right, b->right));
}
int checkFoldable(struct node *root)
{
    if (!root || (!root->right && root->left))
        return 1;
    mirror(root->left);
    int a = isSame(root->left, root->right);
    mirror(root->left);
    return a;
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 7, 9, -1, -1, -1, 15, 11, -1, -1, -1};
    root = create_tree(arr);
    printf("%d", checkFoldable(root));
    return 0;
}