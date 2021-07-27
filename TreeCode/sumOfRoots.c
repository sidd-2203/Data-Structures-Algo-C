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
int check_sum(struct node *root)
{
    if (!root || (!root->right && !root->left))
        return 1;
    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;
    return (root->data == sum && check_sum(root->left) && check_sum(root->right));
    return 0;
}
int main()
{
    struct node *root = NULL;
    int arr[] = {10, 8, 3, -1, -1, 5, -1, -1, 2, 1, -1, -1, -1};
    root = create_tree(arr);
    if (check_sum(root))
        printf("YES");
    else
        printf("NO");
}