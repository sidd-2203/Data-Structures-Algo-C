#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left, *right;
};

struct node *createTree(char in_arr[], char pre_arr[], int st, int end)
{
    if (st >= end)
        return NULL;
    int i, in_index;
    static int index = 0;
    char c = pre_arr[index++];
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = c;
    temp->left = temp->right = NULL;
    for (i = st; i < end; i++)
    {
        if (in_arr[i] == c)
        {
            in_index = i;
            break;
        }
    }
    temp->left = createTree(in_arr, pre_arr, st, in_index);
    temp->right = createTree(in_arr, pre_arr, in_index + 1, end);
    return temp;
}
void traversal_preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%c ->", root->data);
    traversal_preorder(root->left);
    traversal_preorder(root->right);
}
int main(int argc, char const *argv[])
{
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char preorder[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    struct node *tree = createTree(inorder, preorder, 0, 6);
    traversal_preorder(tree);
    return 0;
}
