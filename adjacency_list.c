
#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Create Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a new node
struct Node* createNode(int v, int w) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;

    return newNode;
}

// Create Graph
struct Graph* createGraph(int vertices) {

    struct Graph* graph =
        (struct Graph*)malloc(sizeof(struct Graph));

    graph->numVertices = vertices;

    graph->adjLists =
        (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Add Edge
void addEdge(struct Graph* graph, int src, int dest, int weight) {

    struct Node* newNode = createNode(dest, weight);

    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);

    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print Adjacency List
void printGraph(struct Graph* graph) {

    for (int i = 0; i < graph->numVertices; i++) {

        struct Node* temp = graph->adjLists[i];

        printf("\nVertex %d: ", i);

        while (temp != NULL) {

            printf("(%d, %d) -> ",
                   temp->vertex, temp->weight);

            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main Function
int main() {

    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 3, 4, 2);

    printGraph(graph);

    return 0;
}