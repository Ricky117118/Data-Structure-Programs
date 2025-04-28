#include <stdio.h>
#include <stdbool.h>

#define MAX 20  // Maximum board size, can be increased if needed

int board[MAX];

// Function to print the board
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            (i - row) == (board[i] - col) || 
            (i - row) == (col - board[i])) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve N-Queens problem
void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
            // Backtrack is implicit as we overwrite board[row] in next iteration
        }
    }
}

int main() {
    int n;

    printf("Enter the value of N (number of queens): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input! Please enter N between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Solutions to the %d-Queens problem:\n\n", n);
    solveNQueens(0, n);

    return 0;
}
