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
void traversal_inorder(struct node *root)
{
    if (root == NULL)
        return;
    traversal_inorder(root->left);
    printf("%d ->", root->data);
    traversal_inorder(root->right);
}
void traversal_preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->data);
    traversal_preorder(root->left);
    traversal_preorder(root->right);
}
void traversal_postorder(struct node *root)
{
    if (root == NULL)
        return;
    traversal_postorder(root->left);
    traversal_postorder(root->right);
    printf("%d ->", root->data);
}
int main()
{
    struct node *root = NULL;
    int arr[] = {5, 6, 7, -1, -1, 8, -1, -1, 9, 10, -1, -1, 11, -1, -1};
    root = create_tree(arr);
    printf("InOrder Traversal : ");
    traversal_inorder(root);
    printf("\nPost Order Traversal: ");
    traversal_postorder(root);
    printf("\nPre Order Traversal: ");
    traversal_preorder(root);
}
