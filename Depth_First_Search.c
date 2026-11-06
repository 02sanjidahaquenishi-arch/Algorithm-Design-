
#include <stdio.h>

#define V 5

// DFS Function
void DFS(int adj[V][V], int visited[V], int vertex) {

    // Mark vertex as visited
    visited[vertex] = 1;

    printf("%d ", vertex);

    // Check all adjacent vertices
    for (int i = 0; i < V; i++) {

        if (adj[vertex][i] == 1 && visited[i] == 0) {

            DFS(adj, visited, i);

        }
    }
}

// Main Function
int main() {

    int adj[V][V] = {0};

    int visited[V] = {0};

    // Add Edges
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    printf("DFS Traversal: ");

    DFS(adj, visited, 0);

    return 0;
}