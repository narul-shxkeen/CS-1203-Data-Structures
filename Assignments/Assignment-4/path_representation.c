#include<stdio.h>

#define V 5

void addEdge(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
}

//Storing of paths using adjacency matrix, this has time complexity O(n^2) due to initializing the matrix.
//The method does work on directed graphs.

int main() {
    int graph[V][V] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph (Adjacency Matrix)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
