#include <stdlib.h>
#include <stdio.h> // library for malloc
#define size 100   // setting max length of expression

// each tree node
struct treenode
{
    char data;
    struct treenode *left, *right;
};
//  this function returns the precedence of operators required
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '/' || c == '*' || c == '%')
        return 2;
    else
        return 3;
}
int check_operator(char a) // function returns 1 if the given character is operator is character else 0
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '%')
        return 1;
    return 0;
}
int checkInvalid(char arr[], int n) // function returns 1 if expression is valid else 0
{
    int count_braces = 0;
    for (int i = 0; i < n; i++)
    {
        // if at anytime closing bracket is more than opening it will be invalid
        if (arr[i] == '(')
            count_braces++;
        else if (arr[i] == ')')
            count_braces--;
        else if (check_operator(arr[i]))
        {
            // it checks three condition   1. first or last should not b a operator
            //                             2. just before the operator there should not be any braces
            //                             3. contigious operators are not allowed
            if (i == 0 || i == n - 1 || arr[i - 1] == '(' || check_operator(arr[i - 1]) || check_operator(arr[i + 1]))
                return 0;
        }
        if (count_braces < 0)
            return 0;
    }
    if (count_braces != 0) // atlast also if some unclosed brackets are left its not allowed
        return 0;
    return 1;
}
// creating the tree from the given expression
struct treenode *create_Tree(char arr[], int start, int end)
{
    // printf("%d %d \n", start, end);
    if (start == end) // only if the single number is left
    {
        struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
        temp->data = arr[start];
        temp->left = temp->right = NULL;
        return temp;
    }
    else if (arr[start] == '(' && arr[end] == ')') // solving for the innermost braces
    {
        start++;
        end--;
    }
    int index = 0, curr_precedence = 4;
    int inside_bracket = 0;
    for (int i = start; i <= end; i++)
    {
        // we will search the rightmost lowest precedency operator and outside any brackets
        if (arr[i] == '(')
            inside_bracket++;
        else if (arr[i] == ')')
            inside_bracket--;
        else if (inside_bracket == 0)
        {
            if (check_operator(arr[i]))
            {
                if (precedence(arr[i]) <= curr_precedence)
                {
                    curr_precedence = precedence(arr[i]);
                    index = i;
                }
            }
        }
    }
    // after getting the operator we will put it inside node and check for its right and left child recursively
    struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->data = arr[index];
    // recursively calling for left and right
    temp->left = create_Tree(arr, start, index - 1);
    temp->right = create_Tree(arr, index + 1, end);
    return temp; // returning the node
}
// printing the tree in post order form recursivley to get postfix expression
void post_order_print(struct treenode *root)
{
    if (root)
    {
        post_order_print(root->left);
        post_order_print(root->right);
        printf("%c ", root->data);
    }
}
//  driver or main function
int main(int argc, char const *argv[])
{
    struct treenode *root = NULL;
    char arr[size];
    scanf("%s", &arr);
    int i = 0;
    while (arr[i] && i < size) // it will end when next character is null thereby giving the length of string
        i++;
    int length = i;
    if (checkInvalid(arr, length)) // checking for valid expression
    {
        // making the tree and printing it if it is valid
        root = create_Tree(arr, 0, length - 1);
        post_order_print(root);
    }
    else // message for invalid tree
        printf("Invalid Tree");
    return 0;
}
