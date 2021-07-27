#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left, *right;
    int data;
};
struct stacknode
{
    struct stacknode *next;
    struct node *data;
};
struct stack
{
    struct stacknode *top;
};
void push(struct node *temp, struct stack *stk)
{
    struct stacknode *t = (struct stacknode *)malloc(sizeof(struct stacknode));
    t->data = temp;
    t->next = stk->top;
    stk->top = t;
}
struct node *pop(struct stack *stk)
{
    if (!stk->top)
        return NULL;
    struct node *temp = stk->top->data;
    struct stacknode *free_node = stk->top;
    stk->top = stk->top->next;
    free(free_node);
    return temp;
}
int isEmpty(struct stack *stk)
{
    if (stk->top == NULL)
        return 1;
    return 0;
}
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
void printSpiralForm(struct node *root, struct stack *st1, struct stack *st2)
{
    if (!root)
        return;
    push(root, st1);
    struct node *temp;
    int turn = 1;
    while (!isEmpty(st1) || !isEmpty(st2))
    {
        if (turn == 1)
        {
            temp = pop(st1);
            printf("%d ", temp->data);
            if (temp->left)
                push(temp->left, st2);
            if (temp->right)
                push(temp->right, st2);
            if (isEmpty(st1))
                turn = 2;
        }
        else
        {
            temp = pop(st2);
            printf("%d ", temp->data);
            if (temp->left)
                push(temp->left, st1);
            if (temp->right)
                push(temp->right, st1);
            if (isEmpty(st2))
                turn = 1;
        }
    }
}
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {10, 20, -1, 40, 60, -1, -1, -1, 30, -1, 50, 70, -1, -1, 80, -1, 90, -1, -1};
    root = create_tree(arr);
    struct stack stack1, stack2;
    stack1.top = NULL;
    stack2.top = NULL;
    printSpiralForm(root, &stack1, &stack2);
    return 0;
}