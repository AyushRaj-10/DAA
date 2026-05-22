#include<stdio.h>

int a[10][10], n, indegree[10];

void find_indegree()
{
    int i, j, sum;

    for(j = 0; j < n; j++)
    {
        sum = 0;

        for(i = 0; i < n; i++)
        {
            sum += a[i][j];
        }

        indegree[j] = sum;
    }
}

void topology()
{
    int i, u, v, top = -1;
    int stack[10], t[10], k = 0;

    find_indegree();

    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            stack[++top] = i;
    }

    while(top != -1)
    {
        u = stack[top--];
        t[k++] = u;

        for(v = 0; v < n; v++)
        {
            if(a[u][v] == 1)
            {
                indegree[v]--;

                if(indegree[v] == 0)
                    stack[++top] = v;
            }
        }
    }

    if(k != n)
    {
        printf("Topological sorting not possible (Graph contains cycle)\n");
        return;
    }

    printf("Topological Sequence:\n");

    for(i = 0; i < k; i++)
    {
        printf("%d ", t[i]);
    }
}

int main()
{
    int i, j;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    topology();

    return 0;
}