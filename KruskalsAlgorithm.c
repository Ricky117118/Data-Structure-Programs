#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    return subsets[i].parent;
}


void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}


int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}


void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX]; // Store MST edges
    int resultIndex = 0;

    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (int i = 0; i < E; i++) {
        struct Edge nextEdge = edges[i];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) { // If adding this edge doesn't cause a cycle
            result[resultIndex++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets); 
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    clock_t start,end;
    start=clock();	
    kruskal(edges, V, E);
    end=clock();
    double time_spent=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n",time_spent);	
    return 0;
}
