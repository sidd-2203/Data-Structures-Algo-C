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
                printf("%c", pop(&stk));
            push(&stk, a);
        }
    }
    while (stk.top != -1)
    {
        printf("%c", pop(&stk));
    }
}
