/* ques3b.c - BFS */

#include<stdio.h>

int a[20][20], q[20], visited[20], n;
int i, j, f = -1, r = 0;

void bfs(int v)
{
    q[++r] = v;
    visited[v] = 1;

    while(f <= r)
    {
        for(i = 1; i <= n; i++)
        {
            if(a[v][i] && !visited[i])
            {
                q[++r] = i;
                visited[i] = 1;
            }
        }

        f++;
        v = q[f];
    }
}

int main()
{
    int v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter graph data in matrix form:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &v);

    bfs(v);

    printf("BFS Traversal:\n");

    for(i = 1; i <= r; i++)
    {
        printf("%d\t", q[i]);
    }

    return 0;
}