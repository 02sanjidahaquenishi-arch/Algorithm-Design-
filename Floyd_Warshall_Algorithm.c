
#include <stdio.h>

#define V 5
#define INF 99999

// Floyd Warshall Algorithm
void floydWarshall(int graph[V][V])
{
    int dist[V][V];

    // Copy graph into dist matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] == 0)
                dist[i][j] = INF;
            else
                dist[i][j] = graph[i][j];
        }
    }

    // Update shortest distances
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    printf("Shortest Distance Matrix:\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, 4, 0, 0},
        {2, 0, 1, 7, 0},
        {4, 1, 0, 0, 3},
        {0, 7, 0, 0, 2},
        {0, 0, 3, 2, 0}
    };

    floydWarshall(graph);

    return 0;
}