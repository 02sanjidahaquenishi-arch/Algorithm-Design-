
#include <stdio.h>

#define V 5
#define INF 99999

// Find Minimum Distance Vertex
int findMin(int dist[], int visited[]) {

    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {

        if (visited[i] == 0 && dist[i] < min) {

            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra Function
void dijkstra(int graph[V][V], int start) {

    int dist[V];
    int visited[V] = {0};

    // Initialize Distance
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    // Find Shortest Path
    for (int count = 0; count < V - 1; count++) {

        int u = findMin(dist, visited);

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {

            if (visited[v] == 0 &&
                graph[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print Shortest Distance
    printf("\nShortest Distance from Vertex %d:\n", start);

    for (int i = 0; i < V; i++) {

        if (dist[i] == INF) {
            printf("%d -> %d : Unreachable\n", start, i);
        }
        else {
            printf("%d -> %d : %d\n", start, i, dist[i]);
        }
    }
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

    dijkstra(graph, 0);

    return 0;
}