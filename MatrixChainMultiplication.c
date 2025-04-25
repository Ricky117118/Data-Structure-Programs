#include<stdio.h>
#define MAX 100
#define INF 99999

void printOptimalParenthesis(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("M%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int dp[MAX][MAX];
    int s[MAX][MAX]; // To store the split points
    int i, j, k, l, q;

    for (i = 1; i < n; i++)
        dp[i][i] = 0;

    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            dp[i][j] = INF;
            for (k = i; k < j; k++) {
                q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", dp[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

int main() {
    int n, i;
    int p[MAX];

    printf("\nEnter the number of matrices: ");
    scanf("%d", &n);

    printf("\nEnter dimensions array(size %d):", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    matrixChainOrder(p, n + 1);
    return 0;
}
