
#include <stdio.h>

// Initialize Matrix
void initMatrix(int matrix[5][5], int vertices) {

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Add Edge
void addEdge(int matrix[5][5], int src, int dest) {

    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

// Print Matrix
void printMatrix(int matrix[5][5], int vertices) {

    printf("Adjacency Matrix:\n");

    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

// Main Function
int main() {

    int vertices = 5;
    int matrix[5][5];

    initMatrix(matrix, vertices);

    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 2);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 3);
    addEdge(matrix, 2, 4);
    addEdge(matrix, 3, 4);

    printMatrix(matrix, vertices);

    return 0;
}