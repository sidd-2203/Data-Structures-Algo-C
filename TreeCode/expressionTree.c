#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left, *right;
};
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '/' || c == '*')
        return 2;
    else
        return 3;
}
struct node *createExpressionTree(char arr[], int start, int end)
{
    if (start == end)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[start];
        temp->left = temp->right = NULL;
        return temp;
    }
    int pre = 4;
    int index = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^')
        {
            int t = precedence(arr[i]);
            if (t <= pre)
            {
                pre = t;
                index = i;
            }
        }
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = arr[index];
    temp->left = createExpressionTree(arr, start, index - 1);
    temp->right = createExpressionTree(arr, index + 1, end);
    return temp;
}
void print_inorder(struct node *root)
{
    if (root)
    {
        print_inorder(root->left);
        printf("%c ", root->data);
        print_inorder(root->right);
    }
}

void evaluation(struct node *root)
{
    if (!root->left && !root->right)
        return;
    if (root->left->left == NULL && root->right->right == NULL)
    {
        int l = root->left->data - '0', r = root->right->data - '0';
        switch (root->data)
        {
        case '+':
            root->data = l + r + '0';
            break;
        case '-':
            root->data = l - r + '0';
            break;
        case '*':
            root->data = l * r + '0';
            break;
        case '/':
            root->data = l / r + '0';
            break;
        }
        free(root->left);
        free(root->right);
        root->right = root->left = NULL;
    }
    else
    {
        if (!root->left->left)
            evaluation(root->right);
        else if (!root->right->right)
            evaluation(root->left);
        else
        {
            evaluation(root->right);
            evaluation(root->left);
        }
        evaluation(root);
    }
}
int main(int argc, char const *argv[])
{
    char arr[] = "1*5+3-4/3+6+7+8-9";
    int len = sizeof(arr) / sizeof(arr[0]);
    struct node *root = createExpressionTree(arr, 0, len - 2);
    // print_inorder(root);
    evaluation(root);
    printf("%d", root->data - '0');
    return 0;
}
