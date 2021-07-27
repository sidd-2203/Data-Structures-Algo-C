#include <stdlib.h>
#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
struct node
{
    struct node *left;
    int data;
    struct node *right;
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
// O(n^2) approach--------------------------->start
int height(struct node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int calDiameter(struct node *root)
{
    if (!root)
        return 0;
    int x = height(root->left);
    int y = height(root->right);
    int curr_diameter = x + y + 1;

    int lDiamter = calDiameter(root->left);
    int rDiamter = calDiameter(root->right);
    return max(curr_diameter, max(lDiamter, rDiamter));
}

// --------------> end O(N^2) appraoch

// ---------------> O(N) approach
int nCalDiameter(struct node *root, int *height)
{
    int lh = 0, rh = 0;
    if (!root)
    {
        *height = 0;
        return 0;
    }
    int x = nCalDiameter(root->left, &lh);
    int y = nCalDiameter(root->right, &rh);

    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(x, y));
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    int height = 0;
    printf("%d", nCalDiameter(root, &height));
    return 0;
}
