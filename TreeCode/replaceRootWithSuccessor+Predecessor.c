#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
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
int *in_oder(struct node *temp)
{
    static int a = 0;
    int *arr = (int *)malloc(sizeof(SIZE));
    if (temp)
    {
        in_oder(temp->left);
        arr[a++] = temp->data;
        in_oder(temp->right);
    }
    return arr;
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    return 0;
}