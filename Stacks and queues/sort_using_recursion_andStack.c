#include <stdio.h>
#include <stdlib.h>

#define size 100

struct stack
{
    int *arr;
    int top;
} stk;
void push(struct stack *s1, int a)
{
    s1->top++;
    s1->arr[s1->top] = a;
}
int pop(struct stack *s1)
{
    int x = s1->arr[s1->top];
    s1->top--;
    return x;
}

// Algrorithm-->
// sortStack(stack S)
//if stack is not empty : temp = pop(S);
// sortStack(S);
// sortedInsert(S, temp);

// sortedInsert(Stack S, element)
//     if stack is empty OR element > top element
//         push(S, elem)
//     else
//         temp = pop(S)
//         sortedInsert(S, element)
//         push(S, temp)
void sortStack(struct stack *s)
{
    int temp;
    if (s->top != -1)
        temp = pop(s);
    sortStack(s);
    sortedInsert(s, temp);
}
void sortedInsert(struct stack *s, int element)
{
    int temp;
    if (s->top == -1 || element > s->arr[s->top])
        push(s, element);
    else
        temp = pop(s);
    sortedInsert(s, element);
    push(s, temp);
}

int main()
{
    stk.top = -1;
    int n = 7;
    // printf("Enter the total number of days : ");
    // scanf("%d", &n);
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    for (int i = 0; i < 7; i++)
    {
        push(&stk, price[i]);
    }
    sortStack(&stk);
    for (int i = 0; i < 7; i++)
    {
        pop(&stk);
    }
}