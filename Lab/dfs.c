#include<stdio.h>
#define MAX 20
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Graph
{
    int a[MAX][MAX];
    int n;
    int color[MAX];
    int parent[MAX];
    int discover[MAX];
    int finish[MAX];
    int time;
};

void displayMatrix(int a[MAX][MAX], int n)
{
    int i, j;
    printf("\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

}

void displayArr(int a[MAX], int n)
{
    int i;
    printf("\n");
    for(i=0; i<n; i++)  printf("%d ", a[i]);
    printf("\n");
}

void DFS_visit(struct Graph *graph, int u)
{
    int i;
    graph->color[u] = GRAY;
    graph->discover[u] = graph->time;
    graph->time++;

    for(i=0; i<graph->n; i++)
    {
        if(graph->a[u][i] == 1)
        {
            if(graph->color[i] == WHITE)
            {
                graph->parent[i] = u;
                DFS_visit(graph, i);
            }
        }
    }

    graph->color[u] = BLACK;
    graph->finish[u] = graph->time;
    graph->time++;
}

void DFS(struct Graph *graph)
{
    int i;
    for(i=0; i<graph->n; i++)
    {
        graph->color[i] = WHITE;
        graph->parent[i] = 0;
    }
    graph->time = 0;
    for(i=0; i<graph->n; i++)
    {
        if(graph->color[i] == WHITE)
            DFS_visit(graph, i);
    }
}


int main()
{
    struct Graph graph;
    int i, j;
    graph.n = 8;
    for(i=0; i<graph.n; i++)
        for(j=0; j<graph.n; ++j)
            graph.a[i][j] = 0;

    graph.a[0][1] = graph.a[0][2] = graph.a[0][3] = graph.a[1][4] = graph.a[1][2] = graph.a[2][3] = graph.a[2][4] = graph.a[2][6] = 1;
    graph.a[3][4] = graph.a[3][5] = graph.a[4][6] = graph.a[5][6] = graph.a[5][7] = graph.a[6][7] = 1;

    for(i=0; i<graph.n; i++)
        for(j=0; j<graph.n; ++j)
            if(i<j && graph.a[i][j] == 1) graph.a[j][i] = 1;


    displayMatrix(graph.a, graph.n);
    DFS(&graph);
    displayArr(graph.discover, graph.n);
    displayArr(graph.finish, graph.n);

    struct Graph graph2;
    graph2.n = 6;               //Shameful Confession 2:
                                //I assigned '5' to graph2.n clearly after years of coding I still don't know how to count
    for(i=0; i<graph2.n; i++)
        for(j=0; j<graph2.n; ++j)
            graph2.a[i][j] = 0;

    graph2.a[0][1] = graph2.a[0][2] = graph2.a[0][3] = graph2.a[1][5] = graph2.a[2][4] = graph2.a[3][4] = 1;

    for(i=0; i<graph2.n; i++)
        for(j=0; j<graph2.n; ++j)
            if(i<j && graph2.a[i][j] == 1) graph2.a[j][i] = 1;

    displayMatrix(graph2.a, graph2.n);
    DFS(&graph2);
    displayArr(graph2.discover, graph2.n);
    displayArr(graph2.finish, graph2.n);
    displayArr(graph2.parent, graph2.n);
    return 0;
}
