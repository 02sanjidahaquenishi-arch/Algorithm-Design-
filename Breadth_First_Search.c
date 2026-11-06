
#include <stdio.h>

#define V 5

// BFS Function
void BFS(int adj[V][V], int start) {

    int visited[V] = {0};

    int queue[V];
    int front = 0;
    int rear = 0;

    // Start vertex
    visited[start] = 1;
    queue[rear] = start;
    rear++;

    printf("BFS Traversal: ");

    while (front < rear) {

        int current = queue[front];
        front++;

        printf("%d ", current);

        // Visit all adjacent vertices
        for (int i = 0; i < V; i++) {

            if (adj[current][i] == 1 && visited[i] == 0) {

                visited[i] = 1;

                queue[rear] = i;
                rear++;
            }
        }
    }
}

// Main Function
int main() {

    int adj[V][V] = {0};

    // Add Edges
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    BFS(adj, 0);

    return 0;
}