#include <stdio.h>
#include <stdlib.h>

#define size 100

struct stack
{
    int arr[10];
    int top;
} stk;
void push(int a)
{
    stk.top++;
    stk.arr[stk.top] = a;
}
int pop()
{
    int x = stk.arr[stk.top];
    stk.top--;
    return x;
}
int top()
{
    return stk.arr[stk.top];
}
int main()
{
    // stk.arr = (int *)malloc(sizeof(int) * size);
    stk.top = -1;
    int n = 7;
    int span[7] = {0};
    // printf("Enter the total number of days : ");
    // scanf("%d", &n);
    int price[100] = {100, 80, 60, 70, 60, 75, 85};
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &price[i]);
    // }
    push(0);
    span[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (stk.top != -1 && price[top()] <= price[i])
            pop();
        span[i] = (stk.top == -1) ? (i + 1) : (i - top());
        push(i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", span[i]);
    }

    return 0;
}