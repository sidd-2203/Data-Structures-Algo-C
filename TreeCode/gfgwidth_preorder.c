// C program to calculate width of binary tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int height(struct node *node);
struct node *newNode(int data);

int getMax(int arr[], int n);

void getMaxWidthRecur(struct node *root, int count[], int level);

int getMaxWidth(struct node *root)
{
    int width;
    int h = height(root);

    int *count = (int *)calloc(sizeof(int), h);

    int level = 0;

    getMaxWidthRecur(root, count, level);

    return getMax(count, h);
}

void getMaxWidthRecur(struct node *root, int count[], int level)
{
    if (root)
    {
        count[level]++;
        getMaxWidthRecur(root->left, count, level + 1);
        getMaxWidthRecur(root->right, count, level + 1);
    }
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lHeight = height(node->left);
        int rHeight = height(node->right);

        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    /*
	Constructed bunary tree is:
			1
		/ \
		2 3
	/ \	 \
	4 5	 8
				/ \
			6 7
	*/
    printf("Maximum width is %d \n", getMaxWidth(root));
    getchar();
    return 0;
}
