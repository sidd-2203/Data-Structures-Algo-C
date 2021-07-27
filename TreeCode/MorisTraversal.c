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
void morisInorderTraversal(struct node *root)
{
    struct node *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            struct node *predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr)
                predecessor = predecessor->right;
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                // printf("%d ", curr->data);          // for preorder
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }
    }
}
void print_inorder(struct node *root)
{
    if (root)
    {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);

    printf("Moris traversal----> ");
    morisInorderTraversal(root);
    printf("Inorder correct traversal----> ");
    print_inorder(root);
    return 0;
}
