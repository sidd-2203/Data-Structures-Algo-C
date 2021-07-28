#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6
#define EDGES 7

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

void IsEdge(int **g, int u, int v)
{
    if (g[u][v] == 1)
        printf("Yes there exists an edge between %d and %d ", u, v);
    else
        printf("No, there does not exists an edge between %d and %d ", u, v);
}
void Successors(int **g, int u, int vertices)
{
    for (int i = 1; i <= vertices; i++)
    {
        if (g[u][i] == 1)
        {
            printf("%d ", i);
        }
    }
}
void removeEdge(int **g, int u, int v)
{
    g[u][v] = 0;
    g[v][u] = 0;
}
void AddEdge(int **g, int u, int v)
{
    // int u, v;
    // printf("Enter to and from vertex (maximum vertex can b %d and minimum is 0)", vertices);
    // scanf("%d %d", &u, &v);
    g[u][v] = 1;
    g[v][u] = 1;
}
void toMakeUnreachable(int **g, int vertices)
{
    int count = __INT_MAX__, f;
    for (int i = 1; i <= vertices; i++)
    {
        f = 0;
        for (int j = 1; j <= vertices; j++)
        {
            if (g[i][j] == 1)
                f++;
        }
        count = min(f, count);
    }
    printf("Minimum Number of edges to remove to make some node unreachable is : %d", count);
}

int checkConnected(int **g, int vertices, int pos, int *check_arr, int *count)
{ // pos=1 count=1 initially required

    for (int i = 1; i <= vertices; i++)
    {
        if (g[pos][i] == 1 && check_arr[i] == 0 && i != pos)
        {
            check_arr[i] == 1;
            *count += 1;
            if (*count == vertices)
                break;
            int k = checkConnected(g, vertices, i, check_arr, count);
            if (k == 1)
                return 1;
        }
    }
    if (*count == vertices)
        return 1;
    return 0;
}
int menu()
{
    int choice;
    printf("\n\nEnter 1 to check connected \n");
    printf("Enter 2 Successors of given vertex \n");
    printf("Enter 3 to Check if the edge exits between two vertexs\n");
    printf("Enter 4 to remove an edge \n");
    printf("Enter 5 to check the number of edges to remove to make any node unreachable \n");
    printf("Enter 6 to add an edge \n");
    printf("Enter 7 to Display the matrix\n");
    printf("Enter 8 to Quit ");
    scanf("%d", &choice);
    printf("\n\n");
    return choice;
}

void initialise(int **graph, int vertices)
{
    int Vertex[] = {1, 2, 3, 4, 5, 6}; // just for info
    int Edges[] = {1, 2, 1, 4, 1, 3, 1, 5, 1, 6, 6, 6, 5, 5};

    for (int i = 0; i < 2 * EDGES; i += 2)
    {
        AddEdge(graph, Edges[i], Edges[i + 1]);
    }
}
void Switch_menu(int **g, int vertices)
{
    int k;
    while (1)
    {
        int *check_arr = (int *)calloc((vertices + 1), sizeof(int));
        int r, t, count = 0;
        k = menu();
        switch (k)
        {
        case 1:
            check_arr[1] = 1;
            r = checkConnected(g, vertices, 1, check_arr, &count);
            if (r == 1)
                printf("Connected Graph");
            else
                printf("Not a connected graph");
            break;
        case 2:
            printf("Enter the vertex of whom you want know the succesors : ");
            scanf("%d", &r);
            Successors(g, r, vertices);
            break;
        case 3:
            printf("Enter the vertices of whom you want to check: ");
            scanf("%d%d", &r, &t);
            IsEdge(g, r, t);
            break;
        case 4:
            printf("Enter the vertices between whom you want to remove the edge: ");
            scanf("%d%d", &r, &t);
            removeEdge(g, r, t);
            break;
        case 5:
            toMakeUnreachable(g, vertices);
            break;
        case 6:
            printf("Enter the vertices between whom you want to add the edge: ");
            scanf("%d%d", &r, &t);
            AddEdge(g, r, t);
            break;
        case 7:
            Display_List(g, vertices);
            break;
        case 8:
            exit(1);
            break;
        default:
            break;
        }
        free(check_arr);
    }
}
int main(int argc, char const *argv[])
{
    int links = 1;
    int vertex = 0;
    int vertices = VERTICES;
    // printf("Enter the number of vertices ");
    // scanf("%d", &vertices);
    int **head = (int **)malloc(sizeof(int *) * (vertices + 1));
    for (int i = 0; i <= vertices; i++)
    {
        head[i] = (int *)calloc((vertices + 1), sizeof(int));
    }
    initialise(head, vertices);

    Switch_menu(head, vertices);

    return 0;
}
