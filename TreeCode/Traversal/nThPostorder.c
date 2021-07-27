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
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
void nThPostOrder(struct node *head, int k)
{
    static int count = 0; // important initalization
    if (!head)
        return;
    if (count <= k)
    {
        nThPostOrder(head->left, k);
        nThPostOrder(head->right, k);
        count++;
        if (count == k)
            printf("%d", head->data);
    }
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    nThPostOrder(root, 4);
    return 0;
}