#include <stdio.h>
#include <stdbool.h>
#define V 4
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}
void graphColoring(int graph[V][V], int m) {
    int color[V] = {0};
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return;
    }
    printf("Solution exists! Vertex colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3;  // Number of colors
    graphColoring(graph, m);
    return 0;
}

