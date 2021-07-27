#include <stdio.h>
#include <stdlib.h>
#define sizee 100;
struct stack
{
    int size;
    int top;
    char *s;
};
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 3;
}

struct stack create()
{
    struct stack st;
    st.size = sizee;
    st.top = -1;
    st.s = (char *)malloc(st.size);
    return st;
}

void push(struct stack *st, char n)
{
    if (st->top >= st->size - 1)
    {
        printf("Stack Full\n");
        return;
    }
    else
    {
        st->s[++(st->top)] = n;
    }
}

char pop(struct stack *st)
{
    if (st->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
        return st->s[st->top--];
}

char peek(struct stack st)
{
    if (st.top != -1)
        return st.top;
    else
        return -1;
}

int main()
{
    struct stack stk = create();
    char arr[100];
    int k = 0, a, b;
    printf("Enter the Expression  ");
    scanf("%s", stk.s);
    // printf("%s", stk.s);
    for (int i = 0; stk.s[i] != '\0'; i++)
    {
        char a = stk.s[i];
        if (stk.top == -1)
        {
            push(&stk, a);
        }
        else
        {
            while (precedence(a) <= precedence(stk.s[stk.top]) && stk.top != -1)
                arr[k++] = pop(&stk);
            push(&stk, a);
        }
    }
    while (stk.top != -1)
        arr[k++] = pop(&stk);
    // printf("%s", arr);
    struct stack st = create();

    // There is a problem with this code ...change push and pop to int before using....

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (isDigit(arr[i]))
        {
            push(&st, arr[i]);
        }
        else
        {
            a = pop(&st) - '0';
            b = pop(&st) - '0';
            switch (pop(&st))
            {
            case '+':

                push(&st, a + b);
                break;
            case '*':
                push(&st, a * b);
                break;
            case '-':
                push(&st, a - b);
                break;
            case '/':
                push(&st, a / b);
                break;
            default:
                break;
            }
        }
    }
    printf("%d", pop(&st) - '0');
}
