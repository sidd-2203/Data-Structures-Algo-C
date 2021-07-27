#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int arr[100];
    int i = 0, c;
    c = 0;
    do
    {
        c++;
        a = 0;
        printf("enter elements breadth wise and inout strict binary tree...if some one does has child write -1 : ");
        scanf("%d", &arr[i]);
        printf("if you want to insert more nodes type 1 \n any diff number to end\n");
        scanf("%d", &a);
        i++;
    } while (a == 1);

    for (int i = 0; i < c; i++)
    {
        printf("%d->", arr[i]);
    }
}
