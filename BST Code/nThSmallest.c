#include <stdio.h>
#include <stdlib.h>
struct nodebst
{
    int data;
    struct nodebst *left;
    struct nodebst *right;
    int frequency;
};
struct nodebst *createBSt(struct nodebst *root, int point)
{
    if (root == NULL)
    {
        struct nodebst *root = (struct nodebst *)malloc(sizeof(struct nodebst));
        root->data = point;
        root->left = root->right = NULL;
        root->frequency = 1;
        return root;
    }
    else if (root->data == point)
        root->frequency++;
    else if (root->data < point)
        root->right = createBSt(root->right, point);
    else
        root->left = createBSt(root->left, point);
    return root;
}
void print_inorder(struct nodebst *root)
{
    if (root)
    {
        print_inorder(root->left);
        printf("%d  ", root->data);
        print_inorder(root->right);
    }
}
void nth(struct nodebst *root, int a)
{
    static int x = 1;
    if (root)
    {
        nth(root->left, a);
        if (x == a)
        {
            printf("%d ", root->data);
            x++;
            return;
        }
        x++;
        nth(root->right, a);
    }
}
int main(int argc, char const *argv[])
{
    struct nodebst *root = NULL;
    int arr[] = {5, 3, 2, 4, 6, 8};
    for (int i = 0; i < 6; i++)
    {
        root = createBSt(root, arr[i]);
    }
    nth(root, 5);
}
