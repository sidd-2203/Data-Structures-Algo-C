#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

struct stack create()
{
    struct stack st;
    printf("Enter the max size of stack : ");
    scanf("%d", &st.size);
    st.top = -1;
    st.s = (int *)malloc(st.size);
    return st;
}

void push(struct stack *st, int n)
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

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
        x = st->s[st->top--];
    return x;
}

int peek(struct stack st)
{
    if (st.top != -1)
        return st.top;
    else
        return -1;
}

int main()
{
    struct stack stk = create();

    // Menu driven ....

    while (1)
    {
        printf("Enter 1 for pushing \nEnter 2 for poping the element\nEnter 3 for peeking at top\n4 to exit\n");
        int r, x;
        scanf("%d", &r);
        switch (r)
        {
        case 1:
            printf("Enter a value to push ");
            scanf("%d", &x);
            push(&stk, x);
            break;
        case 2:
            printf("%d", peek(stk));
            break;
        case 3:
            printf("%d", pop(&stk));
        case 4:
            exit(1);
        default:
            break;
        }
    }
    // push(&stk, 1);
    // push(&stk, 2);
    // push(&stk, 3);
    // push(&stk, 4);

    // printf("%d ", pop(&stk));
    // printf("%d ", pop(&stk));
    // printf("%d ", pop(&stk));
    // printf("%d ", pop(&stk));
    // printf("%d ", stk.top);
}
