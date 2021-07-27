#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6
#define EDGES 5

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

void Display_List(int **head, int vertices)
{
    printf("\n");
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("%d ", head[i][j]);
        }
        printf("\n");
    }
}

void removeEdge(int **g, int u, int v)
{
    g[u][v] = 0;
}
void AddEdge(int **g, int u, int v)
{
    g[u][v] = 1;
}

void initialise(int **graph, int vertices)
{
    int Vertex[] = {1, 2, 3, 4, 5, 6}; // just for info
    int Edges[] = {1, 2, 1, 4, 1, 3, 1, 5, 1, 6};

    for (int i = 0; i < 2 * EDGES; i += 2)
    {
        AddEdge(graph, Edges[i], Edges[i + 1]);
    }
}
int checkAcyclic(int **g, int vertices, int *visited, int pos)
{
    // returns 1 if it is not cyclic else
    // 0 for cyclic
    printf("\n");
    for (int i = 1; i <= vertices; i++)
    {
        if (g[pos][i] == 1)
        {
            if (visited[i] == 1)
                return 0;
            else
            {
                printf("%d ", i);
                visited[i] = 1;
                int k = checkAcyclic(g, vertices, visited, i);
                if (k == 1)
                    visited[i] = 0; // Backtracking
                else
                    return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int links = 1;
    int vertex = 0;
    int vertices = VERTICES;

    int **head = (int **)malloc(sizeof(int *) * (vertices + 1));
    for (int i = 0; i <= vertices; i++)
    {
        head[i] = (int *)calloc((vertices + 1), sizeof(int));
    }
    initialise(head, vertices);
    int *visited = (int *)calloc(vertices + 1, sizeof(int));
    visited[1] = 1;
    printf("%d", checkAcyclic(head, vertices, visited, 1));

    return 0;
}
