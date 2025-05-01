#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>  // For memcpy

#define N 4  // Puzzle size (4x4)

// Structure for each puzzle state
typedef struct Node {
    int puzzle[N][N];
    int x, y;        // Blank tile coordinates
    int cost, level;
    struct Node* parent;
} Node;

// Function to print a puzzle state
void printPuzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] == 0)
                printf("   ");
            else
                printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Manhattan Distance heuristic
int calculateCost(int puzzle[N][N], int goal[N][N]) {
    int cost = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (puzzle[i][j] && puzzle[i][j] != goal[i][j]) {
                int targetX = (puzzle[i][j] - 1) / N;
                int targetY = (puzzle[i][j] - 1) % N;
                cost += abs(i - targetX) + abs(j - targetY);
            }
    return cost;
}

// Create a new puzzle node
Node* newNode(int puzzle[N][N], int x, int y, int newX, int newY, int level, Node* parent, int goal[N][N]) {
    Node* node = (Node*)malloc(sizeof(Node));
    memcpy(node->puzzle, puzzle, sizeof(node->puzzle));

    // Swap blank tile
    node->puzzle[x][y] = node->puzzle[newX][newY];
    node->puzzle[newX][newY] = 0;

    node->x = newX;
    node->y = newY;
    node->level = level;
    node->parent = parent;
    node->cost = level + calculateCost(node->puzzle, goal);

    return node;
}

// Solve 15-Puzzle using Branch and Bound
void solvePuzzle(int puzzle[N][N], int x, int y, int goal[N][N]) {
    Node* queue[1000]; // Priority queue (array-based)
    int size = 0;

    queue[size++] = newNode(puzzle, x, y, x, y, 0, NULL, goal);

    while (size) {
        // Find the node with the minimum cost
        int minIdx = 0;
        for (int i = 1; i < size; i++)
            if (queue[i]->cost < queue[minIdx]->cost)
                minIdx = i;

        Node* current = queue[minIdx];

        // Remove it from the queue
        queue[minIdx] = queue[--size];

        // If solved, print solution path
        if (calculateCost(current->puzzle, goal) == 0) {
            printf("Solution found!\n\n");

            // Collect path from start to goal
            Node* path[1000];
            int pathLen = 0;
            while (current) {
                path[pathLen++] = current;
                current = current->parent;
            }

            // Print in correct order
            for (int i = pathLen - 1; i >= 0; i--)
                printPuzzle(path[i]->puzzle);

            return;
        }

        // Possible moves
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N)
                queue[size++] = newNode(current->puzzle, current->x, current->y, newX, newY, current->level + 1, current, goal);
        }
    }

    printf("No solution found!\n");
}

// Driver Function
int main() {
    int puzzle[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 0, 11 },
        { 13, 14, 15, 12 }
    };

    int goal[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 0 }
    };

    int x, y;
    for (x = 0; x < N; x++)
        for (y = 0; y < N; y++)
            if (puzzle[x][y] == 0)
                goto found;

found:
    solvePuzzle(puzzle, x, y, goal);
    return 0;
}