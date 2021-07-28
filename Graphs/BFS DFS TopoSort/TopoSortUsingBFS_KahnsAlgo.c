#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define VERTICES 6
#define EDGES 6
struct stack
{
    int *st;
    int curr;
};
void push(struct stack *stack, int data)
{
    stack->st[stack->curr] = data;
    stack->curr += 1;
}
int pop(struct stack *stack)
{
    if (stack->curr > 0)
    {
        stack->curr -= 1;
        return stack->st[stack->curr];
    }
    return INT_MIN;
}
int isEmpty(struct stack *stack)
{
    if (stack->curr > 0)
        return 0;
    return 1;
}

void AddEdge(int **g, int u, int v)
{
    g[u][v] = 1;
}

void initialise(int **graph, int vertices)
{
    int Vertex[] = {0, 1, 2, 3, 4, 5, 6}; // just for info
    int Edges[] = {1, 2, 1, 4, 1, 3, 1, 5, 1, 6, 6, 3};

    for (int i = 0; i < 2 * EDGES; i += 2)
    {
        AddEdge(graph, Edges[i], Edges[i + 1]);
    }
}
int checkAcyclic(int **g, int vertices, int *visited, int pos)
{
    // returns 1 if it is not cyclic i.e. Acyclic
    // 0 for cyclic
    for (int i = 1; i <= vertices; i++)
    {
        if (g[pos][i] == 1)
        {
            if (visited[i] == 1)
                return 0;
            else
            {
                visited[i] = 1;
                int k = checkAcyclic(g, vertices, visited, i);
                if (k)
                    visited[i] = 0; // Backtracking
                else
                    return 0;
            }
        }
    }
    return 1;
}

void TopoSort(int **g, int vertices)
{
    int *visited = (int *)calloc(vertices + 1, sizeof(int));

    if (checkAcyclic(g, vertices, visited, 1))
    {
        int count = 0;
        int *visited2 = (int *)calloc(vertices + 1, sizeof(int));
        int *indegree = (int *)calloc(vertices + 1, sizeof(int));
        struct stack stack;
        stack.curr = 0;
        stack.st = (int *)calloc(vertices + 1, sizeof(int));
        for (int i = 0; i <= vertices; i++)
            for (int j = 0; j <= vertices; j++)
                indegree[i] += g[j][i];
        while (count != vertices)
        {
            for (int i = 1; i <= vertices; i++)
            {
                if (!indegree[i] && !visited2[i]) // if indegree is 0 and it is not visited
                {
                    count++;
                    visited2[i] = 1;
                    push(&stack, i);
                }
            }
            while (!isEmpty(&stack))
            {
                int k = pop(&stack);
                printf("%d ", k);
                for (int i = 1; i <= vertices; i++)
                    if (g[k][i] == 1)
                        indegree[i]--;
            }
        }
    }
    else
        printf("the graph is not acyclic");
}

int main(int argc, char const *argv[])
{
    int vertex = 0;
    int vertices = VERTICES;

    int **head = (int **)malloc(sizeof(int *) * (vertices + 1));
    for (int i = 0; i <= vertices; i++)
    {
        head[i] = (int *)calloc((vertices + 1), sizeof(int));
    }
    initialise(head, vertices);
    // printf("%d", checkAcyclic(head, vertices, visited, 1));
    TopoSort(head, vertices);

    return 0;
}
