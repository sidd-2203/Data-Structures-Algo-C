#include <stdlib.h>
#include <stdio.h>
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
int check_full(struct node *root)
{
    if (!root || (!root->right && !root->left))
        return 1;
    return (root->left && root->right && check_full(root->right) && check_full(root->left));
    return 0;
}
int main()
{
    struct node *root = NULL;
    int arr[] = {5, 6, 7, -1, -1, 8, -1, -1, 9, 10, -1, -1, -1};
    root = create_tree(arr);
    if (check_full(root))
        printf("FULL BINARY TREE");
    else
        printf("NOT FULL BINARY TREE");
}