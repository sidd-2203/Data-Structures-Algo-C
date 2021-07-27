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
int print_ancestor(struct node *root, int key)
{
    if (!root)
        return 0;
    if (root->data == key)
        return 1;
    if (print_ancestor(root->left, key) || print_ancestor(root->right, key))
    {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    print_ancestor(root, 90);
    return 0;
}
