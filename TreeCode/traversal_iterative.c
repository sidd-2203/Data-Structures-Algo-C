#include <stdio.h>
#include <stdlib.h>
struct node_tree
{
    struct node_tree *left;
    int data;
    struct node_tree *right;
};

struct stack_node
{
    struct node_tree *add;
    struct stack_node *next;
};
struct head
{
    struct stack_node *top;
};
int isEmpty(struct head *stack)
{
    if (stack->top == NULL)
        return 1;
    return 0;
}
void push(struct node_tree *pointer, struct head *stack)
{
    struct stack_node *temp;
    temp = (struct stack_node *)malloc(sizeof(struct stack_node));
    temp->add = pointer;
    temp->next = NULL;
    if (stack->top == NULL)
    {
        stack->top = temp;
    }
    else
    {
        temp->next = stack->top;
        stack->top = temp;
    }
}
struct node_tree *pop(struct head *stack)
{
    struct node_tree *temp;
    struct stack_node *temp2;
    temp = stack->top->add;
    temp2 = stack->top;
    // if (stack->top->next == NULL)
    //     printf("NULL");
    stack->top = stack->top->next;
    free(temp2);
    return temp;
}

struct node_tree *create_tree(int arr[])
{
    static int a = 0;
    struct node_tree *temp;
    int x;
    temp = (struct node_tree *)malloc(sizeof(struct node_tree));
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
int main()
{

    struct head stack_head, stack_head2;
    stack_head.top = NULL;
    struct node_tree *root = NULL, *root2 = NULL;
    int arr[] = {5, 6, 7, -1, -1, 8, -1, -1, 9, 10, -1, -1, 11, -1, -1};
    // root = create_tree(arr);

    // PREORDER TRAVERSAL    ->O(N)
    // printf("PREORDER TRAVERSAL-------->\n");
    // while (!isEmpty(&stack_head) || root != NULL)
    // {
    //     // printf("%d\n", isEmpty(&stack_head));
    //     if (root != NULL)
    //     {
    //         printf("%d-> ", root->data);
    //         push(root, &stack_head);
    //         root = root->left;
    //     }
    //     else
    //     {
    //         root = pop(&stack_head);
    //         root = root->right;
    //     }
    // }
    root2 = create_tree(arr); // this will give error coz a in create function need to be initialized to 0 again--> use one function at atime
    stack_head2.top = NULL;
    // INORDER TRAVERSAL
    printf("\nINORDER TRAVERSAL---------------->>\n");
    while (!isEmpty(&stack_head2) || root2 != NULL)
    {
        if (root2 != NULL)
        {
            push(root2, &stack_head2);
            root2 = root2->left;
        }
        else
        {
            root2 = pop(&stack_head2);
            printf("%d-> ", root2->data);
            root2 = root2->right;
        }
    }
}