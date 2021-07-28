#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6
#define EDGES 7

struct node
{
    int data;
    struct node *next;
};
void Display(struct node **head, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        printf("%d -> ", head[i]->data);
        struct node *temp = head[i]->next;
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void AddEdge(struct node **head, int vertices)
{
    int k = 0;
    int a, b, f1 = 0, f2 = 0;
    int arr[] = {1, 2, 2, 4, 3, 2, 1, 4, 4, 5, 5, 6, 6, 3};
    while (k < 2 * EDGES)
    {
        a = arr[k];
        b = arr[k + 1];
        f1 = 0;
        f2 = 0;
        for (int i = 0; i < vertices; i++)
        {
            if (head[i]->data == a && f1 == 0)
            {
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->next = NULL;
                temp->data = b;
                if (head[i]->next)
                {
                    struct node *run = head[i]->next;
                    while (run->next)
                        run = run->next;
                    run->next = temp;
                }
                else
                    head[i]->next = temp;
                f1++;
            }
            else if (head[i]->data == b && f2 == 0)
            {
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->next = NULL;
                temp->data = a;
                if (head[i]->next)
                {
                    struct node *run = head[i]->next;
                    while (run->next)
                        run = run->next;
                    run->next = temp;
                }
                else
                    head[i]->next = temp;
                f2++;
            }
            if (f1 == 1 && f2 == 1)
                break;
        }
        k += 2;
    }
}
void DFS(struct node **list, int vertices, struct node *dfsnode, int *visited)
{
    if (dfsnode && visited[dfsnode->data] == 0)
    {
        printf("%d ", dfsnode->data);
        visited[dfsnode->data] = 1;
    }
    while (dfsnode)
    {
        if (visited[dfsnode->data] == 0)
        {
            int i = 0;
            for (i = 0; i < vertices; i++)
            {
                if (list[i]->data == dfsnode->data)
                    break;
            }
            DFS(list, vertices, list[i], visited);
        }
        dfsnode = dfsnode->next;
    }
}

int main(int argc, char const *argv[])
{

    int vertices = VERTICES;
    int vertice_array[] = {1, 2, 3, 4, 5, 6};
    int x;
    struct node **head;

    head = (struct node **)malloc(sizeof(struct node *) * VERTICES);
    for (int i = 0; i < VERTICES; i++)
    {
        head[i] = (struct node *)malloc(sizeof(struct node));
        head[i]->data = vertice_array[i];
        head[i]->next = NULL;
    }
    int *visited = (int *)calloc((vertices + 1), sizeof(int));

    AddEdge(head, vertices);
    DFS(head, vertices, head[0], visited);
    // Display(head, vertices);
}