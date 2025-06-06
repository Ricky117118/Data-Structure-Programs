#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = 1000000; // Infinity
    dist[src] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != 1000000 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        if (dist[u] != 1000000 && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    // Print distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int V, E, src;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &V, &E);

    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));

    printf("Enter each edge as source destination weight:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);

    free(edges);
    return 0;
}
