#include <stdio.h>
#include <stdbool.h>
#define V 5
void printSolution(int path[]) {
    printf("Hamiltonian Cycle found:\n");
    for (int i = 0; i < V; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);  // Returning to the start vertex
}
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v])
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
bool hamiltonianCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]];  // Check if cycle completes
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;  // Backtrack
        }
    }
    return false;
}
void hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (!hamiltonianCycleUtil(graph, path, 1)) {
        printf("No Hamiltonian Cycle exists.\n");
        return;
    }
    printSolution(path);
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    hamiltonianCycle(graph);
    return 0;
}
