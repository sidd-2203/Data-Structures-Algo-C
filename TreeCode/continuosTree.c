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

int checkContinuous(struct node *root)
{
    if (!root)
        return 1;
    int f1 = 0, f2 = 0;
    if ((root->left && abs(root->left->data - root->data) <= 1) || !root->left)
        f1 = 1;
    if ((root->right && abs(root->right->data - root->data) <= 1) || !root->right)
        f2 = 1;
    // printf("%d %d\n", f1, f2);
    return f1 && f2 && checkContinuous(root->left) && checkContinuous(root->right);
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {4, 3, 2, -1, -1, 3, -1, -1, 4, 3, -1, -1, 6, -1, -1};
    root = create_tree(arr);
    printf("%d", checkContinuous(root));
    return 0;
}