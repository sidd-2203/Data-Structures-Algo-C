#include <stdio.h>
#include <stdlib.h>
struct nodebst
{
    int data;
    struct nodebst *left;
    struct nodebst *right;
};
struct nodebst *searchRecursive(struct nodebst *root, int cp)
{
    if (root == NULL || root->data == cp)
        return root;
    if (root->data < cp)
        return root->right;
    else
        return root->left;
}
struct nodebst *searchIterative(struct nodebst *root, int cp)
{
    while (root)
    {
        if (root->data == cp)
            return root;
        else if (root->data < cp)
            root = root->right;
        else
            root = root->left;
    }
    return NULL;
}
struct nodebst *search_parent_key(struct nodebst *root, int key)
{
    if (!root || root->data == key)
        return NULL;
    if (root->data < key)
    {
        if (root->right && root->right->data == key)
            return root;
        return search_parent_key(root->right, key);
    }
    else
    {
        if (root->left && root->left->data == key)
            return root;
        return search_parent_key(root->left, key);
    }
}
struct nodebst *createBSt(struct nodebst *root, int point)
{
    if (root == NULL)
    {
        struct nodebst *root = (struct nodebst *)malloc(sizeof(struct nodebst));
        root->data = point;
        root->left = root->right = NULL;
        return root;
    }
    else if (root->data < point)
        root->right = createBSt(root->right, point);
    else
        root->left = createBSt(root->left, point);
    return root;
}
// insert and create are same .....one is recursive and other is iterative
void insert(struct nodebst *root, int cp)
{
    struct nodebst *temp;
    while (root)
    {
        temp = root;
        if (root->data == cp)
            return;
        else if (root->data > cp)
            root = root->left;
        else
            root = root->right;
    }
    root = (struct nodebst *)malloc(sizeof(struct nodebst));
    root->right = root->left = NULL;
    root->data = cp;
    if (root->data < temp->data)
        temp->right = root;
    else
        temp->left = root;
}

void print_inorder(struct nodebst *root)
{
    if (root == NULL)
        return;
    print_inorder(root->left);
    printf("%d  ", root->data);
    print_inorder(root->right);
}
int main(int argc, char const *argv[])
{
    int x;
    struct nodebst *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        head = createBSt(head, x);
    }
    // print_inorder(head);
    struct nodebst *temp = search_parent_key(head, 20);
    printf("%d", temp->data);
    return 0;
}
