#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ll
{
    int data;
    struct ll *next;
};

struct node
{
    struct ll *root;
};

struct ll *insert(struct ll *root, int y)
{
    if (root == NULL)
    {
        struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
        temp->data = y;
        temp->next = NULL;
        root = temp;
        return root;
    }

    struct ll *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct ll *temp1 = (struct ll *)malloc(sizeof(struct ll));
    temp1->data = y;
    temp1->next = NULL;
    temp->next = temp1;
    return root;
}

void display(struct node arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        struct ll *temp = arr[i].root;
        printf("%d-> ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}

int main()
{
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);
    // int arr[n+1][n+1];
    int m;
    printf("Number of edges: ");
    scanf("%d", &m);

    // for adjacency matrix
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         arr[i][j]=0;
    //     }
    // }

    // for(int i=0; i<m; i++){
    //     int x,y;
    //     printf("Enter nodes: ");
    //     scanf("%d %d",&x,&y);
    //     arr[x][y] = arr[y][x] = 1;
    // }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // for adjacency list
    struct node arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i].root = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        printf("Enter nodes: ");
        scanf("%d %d", &x, &y);
        arr[x].root = insert(arr[x].root, y);
        arr[y].root = insert(arr[y].root, x);
    }

    display(arr, n);
    return 0;
}