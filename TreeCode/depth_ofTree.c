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
    // printf("Enter the data : (Enter -1 if there is no node) : ");
    // scanf("%d", &x);
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    // printf("\n/// ------------->Insertion in Preorder form------------->/////\n\n");
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
int depth(struct node *root)
{
    if (!root || !root->left && !root->right)
        return 1;
    int x, y;
    x = depth(root->left);
    y = depth(root->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
    return 0;
}
int main()
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    int y = depth(root);
    printf("%d", y);
}