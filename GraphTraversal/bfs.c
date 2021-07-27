#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6
#define EDGES 7

struct node
{
    int data;
    struct node *next;
};

struct qnode
{
    struct node *node_que;
    struct qnode *next;
};
struct Queue
{
    struct qnode *head;
    struct qnode *curr;
};
void enque(struct Queue *q, struct node *temp)
{
    struct qnode *add = (struct qnode *)malloc(sizeof(struct qnode));
    add->next = NULL;
    add->node_que = temp;
    if (q->head)
    {
        q->curr->next = add;
        q->curr = add;
    }
    else
    {
        q->curr = add;
        q->head = add;
    }
}
struct node *dequeue(struct Queue *q)
{
    if (q->head)
    {
        struct qnode *temp = q->head;
        struct node *temp_node = temp->node_que;
        q->head = q->head->next;
        free(temp);
        return temp_node;
    }
    return NULL;
}

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

int isEmpty(struct Queue *q)
{
    // returns 1 if q is empty
    if (q->head)
        return 0;
    return 1;
}
void BFS(struct node **head, int vertices)
{
    struct Queue myq;
    myq.head = NULL;
    myq.curr = NULL;
    int *visited;
    visited = (int *)malloc(sizeof(int) * (vertices + 1));
    for (int i = 0; i <= vertices; i++)
        visited[i] = 0;
    if (head[0])
    {
        enque(&myq, head[0]);
        visited[head[0]->data] = 1;
        while (!isEmpty(&myq))
        {
            struct node *temp = dequeue(&myq);
            printf("%d ", temp->data);
            while (temp)
            {
                if (visited[temp->data] == 0)
                {
                    for (int i = 0; i < vertices; i++)
                    {
                        if (head[i]->data == temp->data)
                        {
                            enque(&myq, head[i]);
                            break;
                        }
                    }
                    visited[temp->data] = 1;
                }
                temp = temp->next;
            }
        }
    }
    else
        printf("There are no vertices to travel ");
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

    AddEdge(head, vertices);
    // Display(head, vertices);
    BFS(head, vertices);

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
