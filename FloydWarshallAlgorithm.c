#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[V][V]);

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[][] for each vertex as intermediate
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the final shortest distance matrix
    printSolution(dist);
}

void printSolution(int dist[V][V]) {
    int i, j;
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
         {0,   3,  INF, 5},
        {2, 0,   INF, 4},
        {INF, 1, 0,   INF},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph);
    return 0;
}
