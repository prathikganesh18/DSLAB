#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear;
}

void BFS(int start, int n)
{
    int i;
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty())
    {
        int v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    BFS(start, n);

    return 0;
}