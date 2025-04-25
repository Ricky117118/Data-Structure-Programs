#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define V 5 // Number of vertices in the graph
#define INF 99999 //infinity

int selectMinVertex(int key[], bool mstSet[]) {
    int min = INF;
    int vertex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            vertex = i;
        }
    }
    return vertex;
}

void primsAlgorithm(int graph[V][V]) {
    int parent[V]; //store the MST
    int key[V];    //store the minimum weight
    bool mstSet[V]; //track vertices included in the MST

    // Initialize all keys and mstSet
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        // Select the minimum vertex
        int u = selectMinVertex(key, mstSet);
        mstSet[u] = true;

        // Update keys and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    clock_t start, end;
    start = clock();

    primsAlgorithm(graph);

    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_spent);

    return 0;
}
