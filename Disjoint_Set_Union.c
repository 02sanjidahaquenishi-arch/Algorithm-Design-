
#include <stdio.h>

#define V 5

int parent[V];
int groupSize[V];

// Find Root
int findRoot(int u)
{
    if (parent[u] == u)
    {
        return u;
    }

    parent[u] = findRoot(parent[u]);

    return parent[u];
}

// Union
int unite(int u, int v)
{
    int rootU = findRoot(u);
    int rootV = findRoot(v);

    if (rootU == rootV)
    {
        return 0;
    }

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

int main()
{
    // Initialize DSU
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        groupSize[i] = 1;
    }

    unite(0, 1);
    unite(1, 2);
    unite(3, 4);

    printf("Are 0 and 2 connected? ");

    if (findRoot(0) == findRoot(2))
        printf("YES\n");
    else
        printf("NO\n");

    printf("Are 0 and 4 connected? ");

    if (findRoot(0) == findRoot(4))
        printf("YES\n");
    else
        printf("NO\n");

    unite(2, 4);

    printf("After Union, are 0 and 4 connected? ");

    if (findRoot(0) == findRoot(4))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}