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
int check_skew(struct node *root)
{
    if (root == NULL)
        return 1;
    if (root->left && root->right)
        return 0;
    if (!root->left && !root->right)
        return 1;
    else if (root->left)
        return check_skew(root->left);
    else if (root->right)
        return check_skew(root->right);
    return 0;
}
int main()
{
    struct node *root = NULL;
    int arr[] = {5, 4, -1, 3, 2, -1, -1, -1, -1};
    root = create_tree(arr);
    if (check_skew(root))
        printf("skewed tree");
    else
        printf("NOT a skewed Tree");
}