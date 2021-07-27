#include <bits/stdc++.h>
using namespace std;
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
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
void changeitems(struct node *root, int level)
{
    if (!root)
        return;
    if (level % 2 == 0)
    {
        // look at the link please       https://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
    }
}
void printInorder(struct node *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->data << "  ";
        printInorder(root->right);
    }
}
int main(int argc, char const *argv[])
{

    struct node *root = NULL;

    int arr[] = {1, 2, 4, 8, 16, -1, -1, 17, -1, -1, 9, 18, -1, -1, 19, -1, -1, 5, 10, 20, -1, -1, 21,
                 -1, -1, 11, 22, -1, -1, 23, -1, -1, 3, 6, 12, 24, -1, -1, 25, -1, -1,
                 13, 26, -1, -1, 27, -1, -1, 7, 14, 28, -1, -1, 29, -1, -1, 15, 30, -1, -1, 31, -1, -1};

    root = create_tree(arr);
    changeitems(root, 0);
    printInorder(root);
    return 0;
}
