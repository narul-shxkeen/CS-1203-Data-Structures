#include <stdio.h>
#include <stdlib.h>

// Define the structure for an adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Define the structure for an adjacency list
typedef struct List {
    Node *head;
} List;

// Define the structure for a graph
typedef struct Graph {
    int V;
    List* array;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int dest) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (List*) malloc(V * sizeof(List));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to a directed graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to print the adjacency list representation of graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    // Create the graph given in above figure
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
