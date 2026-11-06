
#include <stdio.h>

#define V 5
#define E 6

int parent[V];
int groupSize[V];

struct Edge
{
    int src;
    int dest;
    int weight;
};

// Find Root
int findRoot(int u)
{
    if (parent[u] == u)
        return u;

    parent[u] = findRoot(parent[u]);

    return parent[u];
}

// Union
int unite(int u, int v)
{
    int rootU = findRoot(u);
    int rootV = findRoot(v);

    if (rootU == rootV)
        return 0;

    if (groupSize[rootU] < groupSize[rootV])
    {
        int temp = rootU;
        rootU = rootV;
        rootV = temp;
    }

    parent[rootV] = rootU;
    groupSize[rootU] += groupSize[rootV];

    return 1;
}

// Sort Edges
void sortEdges(struct Edge edges[])
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal Algorithm
void kruskal(struct Edge edges[])
{
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        groupSize[i] = 1;
    }

    sortEdges(edges);

    int total = 0;
    int count = 0;

    printf("Minimum Spanning Tree:\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (unite(u, v))
        {
            printf("%d - %d : %d\n",
                   u, v, edges[i].weight);

            total += edges[i].weight;
            count++;

            if (count == V - 1)
                break;
        }
    }

    printf("Total MST Weight = %d\n", total);
}

int main()
{
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 2}
    };

    kruskal(edges);

    return 0;
}