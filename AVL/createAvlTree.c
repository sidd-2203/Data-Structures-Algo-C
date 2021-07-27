#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
    int height;
    int freq;
};
int height(struct node *root)
{
    int lh = 0, rh = 0;
    if (!root)
        return 0;
    else
    {
        if (root->left)
            lh = 1 + root->left->height;
        if (root->right)
            rh = 1 + root->right->height;
        return lh > rh ? lh : rh;
    }
}
struct node *singleLeft(struct node *root)
{
    struct node *rightOfRoot = root->right;
    struct node *left_To_rightOfRoot = root->right->left;
    rightOfRoot->left = root;
    root->right = left_To_rightOfRoot;
    root->height = height(root);
    rightOfRoot->height = height(rightOfRoot);
    return rightOfRoot;
}
struct node *singleRight(struct node *root)
{
    struct node *leftOfRoot = root->left, *right_toleftOfRoot = root->left->right;
    leftOfRoot->right = root;
    root->left = right_toleftOfRoot;
    root->height = height(root);
    leftOfRoot->height = height(leftOfRoot);
    return leftOfRoot;
}
struct node *LL(struct node *root)
{
    root = singleRight(root);
    return root;
}
struct node *RR(struct node *root)
{
    root = singleLeft(root);
    return root;
}
struct node *LR(struct node *root)
{

    root->left = singleLeft(root->left);
    root = singleRight(root);
    return root;
}
struct node *RL(struct node *root)
{
    root->right = singleRight(root->right);
    root = singleLeft(root);
    return root;
}

struct node *newnode(int a)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->height = 0;
    temp->left = temp->right = NULL;
    temp->freq = 1;
    return temp;
}
int balance_factor(struct node *root)
{
    if (!root || root->height == 0)
        return 0;
    else
    {
        if (!root->left)
            return -root->right->height;
        else if (!root->right)
            return root->left->height;
        else
            return root->left->height - root->right->height;
    }
}

struct node *createAvl(int key, struct node *root)
{
    if (!root)
        root = newnode(key);
    else
    {
        if (root->data == key)
            root->freq = root->freq + 1;
        if (root->data > key)
        {
            root->left = createAvl(key, root->left);
            root->height = height(root);
            if (balance_factor(root) == 2)
            {
                if (key < root->left->data)
                    root = LL(root);
                else
                    root = LR(root);
            }
        }
        else
        {
            root->right = createAvl(key, root->right);
            root->height = height(root);
            if (balance_factor(root) == -2)
            {
                if (key > root->right->data)
                    root = RR(root);
                else
                    root = RL(root);
            }
        }
    }
    return root;
}
void print_inorder(struct node *root)
{
    if (root)
    {
        print_inorder(root->left);
        printf("%d  %d\t\t", root->data, root->height);
        print_inorder(root->right);
    }
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {36, 45, 63, 54, 72, 89};
    for (int i = 0; i < 6; i++)
    {
        root = createAvl(arr[i], root);
        print_inorder(root);
        printf("\n\n");
    }
    return 0;
}
