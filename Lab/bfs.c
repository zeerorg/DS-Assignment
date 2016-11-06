#include<stdio.h>

#define MAX 20

struct queue
{
    int arr[MAX];
    int beg, end;
};
/* QUEUE FUNCTIONS */
/* ************************************* */
void insert(struct queue *q, int x)
{
    if(q->end == 99)    printf("Queue Full.!\n");

    else if(q->end == -1)
    {
        q->beg = q->end = 0;
        q->arr[q->end] = x;
    }

    else                q->arr[++q->end] = x;
}

int del(struct queue *q)
{
    if(q->beg == -1)    return -1;

    int result = q->arr[q->beg];

    if(q->beg == q->end)    q->beg = q->end = -1;

    else                    q->beg++;
    return result;
}

int isEmpty(struct queue q)
{
    if(q.beg == -1)
        return 1;
    return 0;
}
/* *************************** */

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

void BFS(int a[MAX][MAX], int n, int start)
{
    int i, u, j;
    struct queue q;
    int visit[MAX];
    int parent[MAX];
    int distance[MAX];
    q.beg = q.end = -1;
    for(i=0; i<n; ++i)  //Shameful Confession:
    {                   //I did ++n instead of ++i took me 30 minutes to notice
        parent[i] = 0;
        visit[i] = 0;
        distance[i] = 0;
    }
    displayArr(parent, n);
    insert(&q, start);
    visit[start] = 1;
    while(isEmpty(q) != 1)
    {
        u = del(&q);
        printf("\nVertex: %d", u);
        for(i=0; i<n && u >= 0; i++)
        {
            if(a[u][i] == 1)
            {
                if(visit[i] == 0)
                {
                    insert(&q, i);
                    visit[i] = 1;
                    distance[i] = distance[u] + 1;
                    parent[i] = u;
                }
            }
        }
    }
    displayArr(parent, n);
}

int main()
{
    int a[MAX][MAX], n=8, i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; ++j)
            a[i][j] = 0;

    a[0][1] = a[0][2] = a[0][3] = a[1][4] = a[2][4] = a[2][6] = 1;
    a[3][4] = a[3][5] = a[4][6] = a[5][7] = a[6][7] = 1;

    for(i=0; i<n; i++)
        for(j=0; j<n; ++j)
            if(i<j && a[i][j] == 1) a[j][i] = 1;


    displayMatrix(a, n);
    BFS(a, n, 0);
}
