
#include <stdio.h>

#define V 5
#define INF 99999

// Find Minimum Key
int findMin(int key[], int mstSet[]) {

    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {

        if (mstSet[i] == 0 && key[i] < min) {

            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Prim's Algorithm
void prim(int graph[V][V]) {

    int parent[V];
    int key[V];
    int mstSet[V] = {0};

    // Initialize Key
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    // Find MST
    for (int count = 0; count < V - 1; count++) {

        int u = findMin(key, mstSet);

        if (u == -1) {
            printf("Graph is disconnected!\n");
            return;
        }

        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {

            if (graph[u][v] != 0 &&
                mstSet[v] == 0 &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    int total = 0;

    printf("\nMinimum Spanning Tree:\n");

    for (int i = 1; i < V; i++) {

        printf("%d - %d : %d\n",
               parent[i], i, key[i]);

        total = total + key[i];
    }

    printf("\nTotal MST Weight = %d\n", total);
}

// Main Function
int main() {

    int graph[V][V] = {

        {0, 2, 4, 0, 0},
        {2, 0, 1, 7, 0},
        {4, 1, 0, 0, 3},
        {0, 7, 0, 0, 2},
        {0, 0, 3, 2, 0}
    };

    prim(graph);

    return 0;
}