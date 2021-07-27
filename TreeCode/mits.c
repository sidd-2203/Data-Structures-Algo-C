#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *right, *left;
};

struct node *create(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *newroot = (struct node *)malloc(sizeof(struct node));
        newroot->data = val;
        newroot->right = NULL;
        newroot->left = NULL;
        root = newroot;
        return newroot;
    }
    else
    {
        if (val < root->data)
            root->left = create(root->left, val);
        else
            root->right = create(root->right, val);
        return root;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }
    else if (root->data == key)
        return root;
    else
    {
        struct node *curr = root;
        while (curr != NULL)
        {
            if (curr->data < key)
                curr = curr->right;
            else if (curr->data > key)
                curr = curr->left;
            else
                return curr;
        }
        if (curr == NULL)
            return NULL;
    }
}
void deletion(struct node *temp, int key)
{
    if (temp->right == NULL && temp->left == NULL)
    {
        printf("%d will be deleted\n", temp->data);
        free(temp);
    }
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int val, ch;
    struct node *root;
    root = NULL;
    while (1)
    {
        printf("Enter choice:");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter value:");
            scanf("%d", &val);
            root = create(root, val);
        }
        else if (ch == 2)
        {
            printf("Enter value to be searched:");
            scanf("%d", &val);
            struct node *temp = search(root, val);
            if (temp == NULL)
                printf("Element is not present in tree\n");
            else
                printf("%d is found\n", temp->data);
        }
        else if (ch == 3)
            printInorder(root);
        else if (ch == 4)
        {
            printf("Enter value to be deleted:");
            scanf("%d", &val);
            struct node *temp = search(root, val);
            deletion(temp, val);
        }
        else if (ch == 5)
            exit(0);
    }
    return 0;
}