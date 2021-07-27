#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
    int height;
    int frequency;
};

// bst delete used
struct node *in_succesor(struct node *root)
{
    if (!root)
        return NULL;
    while (root->left)
        root = root->left;
    return root;
}
struct node *in_predecessor(struct node *root)
{
    if (!root)
        return NULL;
    while (root->right)
        root = root->right;
    return root;
}
struct node *parent(struct node *root, int key)
{
    if (!root || (root->right && root->right->data == key || (root->left && root->left->data == key)))
        return root;
    else if (!root->left && !root->right)
        return NULL;
    else if (key > root->data)
        return parent(root->right, key);
    else
        return parent(root->left, key);
}
void delete (struct node *root, int key, struct node *head)
{
    if (!root)
        return;
    else
    {
        if (root->right && root->left || root->right) // if both childs exists or only right child exists
        {
            struct node *in_s = in_succesor(root->right);
            struct node *in_sparent = parent(head, in_s->data);
            root->data = in_s->data;
            if (in_sparent != root)
                in_sparent->left = in_s->right;
            else
                in_sparent->right = in_s->right;
            free(in_s);
        }
        else if (root->left) // if only left child exists
        {
            struct node *in_p = in_predecessor(root->left);
            struct node *in_pParent = parent(head, in_p->data);
            root->data = in_p->data;
            if (in_pParent != root)
                in_pParent->right = in_p->left;
            else
                in_pParent->left = in_p->left;
            free(in_p);
        }
        else
        { // if no child exist
            struct node *par = parent(head, key);
            if (par)
            {
                if (par->left == root)
                    par->left = NULL;
                if (par->right == root)
                    par->right = NULL;
            }
            else
                head = NULL;
            free(root);
        }
    }
}
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
    temp->frequency = 1;
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
            root->frequency = root->frequency + 1;
        else if (root->data > key)
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
void bf_2(struct node *root)
{
    if (balance_factor(root->right) <= 0)
        root = RR(root);
    else
        root = RL(root);
}
void bf2(struct node *root)
{
    if (balance_factor(root->left) < 0)
        root = LR(root);
    else
        root = LL(root);
}
struct node *deleteavl(struct node *root, int key, struct node *head)
{
    if (!root)
        return root;
    if (root->data == key)
    {
        delete (root, key, head);
        if (balance_factor(root) == -2) // deleted from left then imbalance would be toward right need to correct right
            // if root->right balance factor is <=0   RR else RL
            bf_2(root);
        if (balance_factor(root) == 2) // deleted from right then imbalance would be towards left need to correct left
            // if root-left balance factor is <0 LR else LL
            bf2(root);
    }
    else
    {
        if (key < root->data)
        {
            root->left = deleteavl(root->left, key, head);
            root->height = height(root);
            if (balance_factor(root) == -2) // deleted from left then imbalance would be toward right need to correct right
                // if root->right balance factor is <=0   RR else RL
                bf_2(root);
        }
        else
        {
            root->right = deleteavl(root->right, key, head);
            root->height = height(root);
            if (balance_factor(root) == 2) // deleted from right then imbalance would be towards left need to correct left
                // if root-left balance factor is <0 LR else LL
                bf2(root);
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
    deleteavl(root, 54, root);
    print_inorder(root);
    return 0;
}
