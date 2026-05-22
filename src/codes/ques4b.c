/* ques4b.c - Topological Sort using Queue */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int n;
int adj[MAX][MAX];

int queue[MAX], front = -1, rear = -1;

void insert_queue(int v)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1)
            front = 0;

        queue[++rear] = v;
    }
}

int delete_queue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    return queue[front++];
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;

    return 0;
}

int indegree(int v)
{
    int i, in_deg = 0;

    for(i = 0; i < n; i++)
    {
        if(adj[i][v] == 1)
            in_deg++;
    }

    return in_deg;
}

void create_graph()
{
    int i, max_edges, origin, destin;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    max_edges = n * (n - 1);

    for(i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d (-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if(origin == -1 && destin == -1)
            break;

        if(origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid edge\n");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

int main()
{
    int i, v, count;
    int topo_order[MAX], indeg[MAX];

    create_graph();

    for(i = 0; i < n; i++)
    {
        indeg[i] = indegree(i);

        if(indeg[i] == 0)
            insert_queue(i);
    }

    count = 0;

    while(!isEmpty_queue() && count < n)
    {
        v = delete_queue();

        topo_order[count++] = v;

        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1)
            {
                adj[v][i] = 0;
                indeg[i]--;

                if(indeg[i] == 0)
                    insert_queue(i);
            }
        }
    }

    if(count < n)
    {
        printf("No topological ordering possible\n");
        return 1;
    }

    printf("Topological Order:\n");

    for(i = 0; i < count; i++)
    {
        printf("%d ", topo_order[i]);
    }

    return 0;
}