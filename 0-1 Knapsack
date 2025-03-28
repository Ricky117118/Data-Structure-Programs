#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int **dp = (int **)malloc((n+1) * sizeof(int *));
    int i, w;
    for (i = 0; i <= n; i++) 
        dp[i] = (int *)malloc((W+1) * sizeof(int));

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int ans = dp[n][W];
    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int i;
    int *values = (int*)malloc(n * sizeof(int));
    int *weights = (int*)malloc(n * sizeof(int)); 
    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Items :\t\t");
    for(i = 0; i < n; i++)
        printf("Item%d\t",i+1);
    printf("\nWeights :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",weights[i]);
    printf("\nValues :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",values[i]);

    clock_t t = clock();
    int maxValue = knapsack(W, weights, values, n);
    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\nThe maximum value that can be obtained is: %d\n", maxValue);
    printf("Time taken : %f seconds\n", time);
    free(values);
    free(weights);
    return 0;
}
