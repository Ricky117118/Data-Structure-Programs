#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void printPuzzle(int puzzle[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 0)
                printf("   ");
            else
                printf("%3d", puzzle[i][j]);
        }
        printf("\n");
    }
}

void shufflePuzzle(int puzzle[SIZE][SIZE]) {
    int nums[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++)
        nums[i] = i;

    // Fisher-Yates shuffle
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int idx = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            puzzle[i][j] = nums[idx++];
}

int isSolved(int puzzle[SIZE][SIZE]) {
    int expected = 1;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            if (i == SIZE - 1 && j == SIZE - 1)
                return puzzle[i][j] == 0;
            if (puzzle[i][j] != expected++)
                return 0;
        }
    return 1;
}

void findBlank(int puzzle[SIZE][SIZE], int *x, int *y) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (puzzle[i][j] == 0) {
                *x = i;
                *y = j;
                return;
            }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveTile(int puzzle[SIZE][SIZE], char move) {
    int x, y;
    findBlank(puzzle, &x, &y);
    if (move == 'w' && x < SIZE - 1)
        swap(&puzzle[x][y], &puzzle[x + 1][y]);
    else if (move == 's' && x > 0)
        swap(&puzzle[x][y], &puzzle[x - 1][y]);
    else if (move == 'a' && y < SIZE - 1)
        swap(&puzzle[x][y], &puzzle[x][y + 1]);
    else if (move == 'd' && y > 0)
        swap(&puzzle[x][y], &puzzle[x][y - 1]);
    else
        printf("Invalid move!\n");
}

int main() {
    int puzzle[SIZE][SIZE];
    char move;
    srand(time(NULL));

    shufflePuzzle(puzzle);

    while (1) {
        printPuzzle(puzzle);
        if (isSolved(puzzle)) {
            printf("Congratulations! Puzzle Solved!\n");
            break;
        }
        printf("Enter move (w=up, s=down, a=left, d=right): ");
        scanf(" %c", &move);
        moveTile(puzzle, move);
    }

    return 0;
}