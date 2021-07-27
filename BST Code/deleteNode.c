#include <stdio.h>
#include <stdlib.h>
struct nodebst
{
    int data;
    struct nodebst *left;
    struct nodebst *right;
    int frequency;
};

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
int check_child(struct nodebst *root)
{
    int ans = 0;
    if (root->left && root->right)
        ans = 3;
    else if (root->left)
        ans = 1;
    else if (root->right)
        ans = 2;
    return ans;
}
struct nodebst *in_succesor(struct nodebst *root)
{
    if (!root)
        return NULL;
    while (root->left)
        root = root->left;
    return root;
}
struct nodebst *in_predecessor(struct nodebst *root)
{
    if (!root)
        return NULL;
    while (root->right)
        root = root->right;
    return root;
}
struct nodebst *parent(struct nodebst *root, int key)
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
void delete (struct nodebst *root, int key, struct nodebst *head)
{
    if (!root)
        return;
    if (root->data > key)
        delete (root->left, key, head);
    else if (root->data < key)
        delete (root->right, key, head);
    else
    {
        if (root->right && root->left || root->right) // if both childs exists or only right child exists
        {
            struct nodebst *in_s = in_succesor(root->right);
            struct nodebst *in_sparent = parent(head, in_s->data);
            root->data = in_s->data;
            if (in_sparent != root)
                in_sparent->left = in_s->right;
            else
                in_sparent->right = in_s->right;
            free(in_s);
        }
        else if (root->left)
        {
            struct nodebst *in_p = in_predecessor(root->left);
            struct nodebst *in_pParent = parent(head, in_p->data);
            root->data = in_p->data;
            if (in_pParent != root)
                in_pParent->right = in_p->left;
            else
                in_pParent->left = in_p->left;
            free(in_p);
        }
        else
        {
            struct nodebst *par = parent(head, key);
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

/*
From the logic of tutorial followed -->taken only 2 cases
struct nodebst *delete (struct nodebst *root, int key)
{
    if (!root)
        return NULL;
    if (!root->right && root->left)
    {
        free(root);
        return NULL;
    }
    if (root->data < key)
        root->right = delete (root->right, key);
    else if (root->data > key)
        root->left = delete (root->left, key);
    else
    {
        if (root->right)
        {
            struct nodebst *succesor = in_succesor(root->right);
            if (succesor)
            {
                root->data = succesor->data;
                free(succesor);
                return NULL;
            }
        }
        else
        {
            struct nodebst *prede = in_pre(root->left);
        }
    }
} */
void print_inorder(struct nodebst *root)
{
    if (root)
    {
        print_inorder(root->left);
        printf("%d  ", root->data);
        print_inorder(root->right);
    }
}
int main(int argc, char const *argv[])
{
    struct nodebst *root = NULL;
    int arr[] = {60, 23, 12};
    for (int i = 0; i < 3; i++)
    {
        root = createBSt(root, arr[i]);
    }
    int x, y;
    printf("Enter the number of values to be deleted:");
    scanf("%d", &x);
    printf("Before deleting\n ");
    print_inorder(root);
    printf("\n\n");

    // one node deletion is still left in this code
    for (int i = 0; i < x && i < 3; i++)
    {

        printf("Enter the value to be deleted");
        scanf("%d", &y);
        printf("after deleting \n ");
        delete (root, y, root);
        print_inorder(root);
        printf("\n\n");
    }

    return 0;
}
