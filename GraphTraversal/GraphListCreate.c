#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6
#define EDGES 7

struct connectionNode
{
    int data;
    struct connectionNode *next;
};

struct listnode
{

    int vertice;
    struct connectionNode *next;
};
int Menu()
{
    int choice;
    printf("Enter 1 for adding and edge\n");
    printf("Enter 2 for adding and Vertice\n");
    scanf("%d", &choice);
    return choice;
}

void Display(struct listnode **head, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        printf("%d -> ", head[i]->vertice);
        struct connectionNode *temp = head[i]->next;
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void AddEdge(struct listnode **head, int vertices)
{
    int k = 0;
    int a, b, f1 = 0, f2 = 0;
    int arr[] = {1, 2, 2, 4, 3, 2, 1, 4, 4, 5, 5, 6, 6, 3};
    // printf("Enter the from and to vertice");
    // scanf("%d%d", &a, &b);
    while (k < 2 * EDGES)
    {
        a = arr[k];
        b = arr[k + 1];
        f1 = 0;
        f2 = 0;
        for (int i = 0; i < vertices; i++)
        {
            // printf("%d %d \n", a, b);
            if (head[i]->vertice == a && f1 == 0)
            {
                struct connectionNode *temp = (struct connectionNode *)malloc(sizeof(struct connectionNode));
                temp->next = NULL;
                temp->data = b;
                if (head[i]->next)
                {
                    struct connectionNode *run = head[i]->next;
                    while (run->next)
                        run = run->next;
                    run->next = temp;
                }
                else
                    head[i]->next = temp;
                f1++;
            }
            // FOr directed graph remove this line
            else if (head[i]->vertice == b && f2 == 0)
            {
                struct connectionNode *temp = (struct connectionNode *)malloc(sizeof(struct connectionNode));
                temp->next = NULL;
                temp->data = a;
                if (head[i]->next)
                {
                    struct connectionNode *run = head[i]->next;
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

int main(int argc, char const *argv[])
{

    int vertices = VERTICES;
    // printf("Enter the number of vertices ");
    // scanf("%d", &vertices);
    int vertice_array[] = {1, 2, 3, 4, 5, 6};
    int x;
    struct listnode **head;
    head = (struct listnode **)malloc(sizeof(struct listnode *) * VERTICES);
    for (int i = 0; i < VERTICES; i++)
    {
        // printf("Enter the vertice number : ");
        // scanf("%d", &x);
        head[i] = (struct listnode *)malloc(sizeof(struct listnode));
        head[i]->vertice = vertice_array[i];
        head[i]->next = NULL;
        // printf("%d ", head[i]->data);
    }

    // printf("if you want to add edge type 1 ");
    // scanf("%d", &k);
    // if (k != 1)
    //     break;

    AddEdge(head, vertices);
    // printf("\n\n");
    Display(head, vertices);

    return 0;
}

/*

List by array
#include <stdio.h>
#include <stdlib.h>
#define VERTICES 1

typedef struct graphNode
{
    int data;
} graph;
void Display_List(graph **head, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        int size = sizeof(head[i]) / sizeof(graph);
        for (int j = 0; j < size; j++)
        {
            printf("%d ", head[i][j].data);
        }
    }
}

int main(int argc, char const *argv[])
{
    int links = 1;
    int vertex = 0;
    int vertices = VERTICES;
    graph **head = (graph **)malloc(sizeof(graph *) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        printf("Enter the vertice and number of links");
        scanf("%d %d", &vertex, &links);
        head[i] = (graph *)malloc(sizeof(graph) * (links + 1));
        head[i]->data = vertex;
        for (int j = 1; j < links; j++)
        {
            printf("Enter the %d connection ", j);
            scanf("%d", &head[i][j].data);
        }
    }
    Display_List(head, vertices);
    // printf("%d %d %d ", head[0]->data, head[0][0].data, head[0][1].data);

    return 0;
}
*/
