#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

void sortItemsByRatio(Item items[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(Item items[], int n, int capacity) {
    sortItemsByRatio(items, n);
    int i;
    float maxValue = 0.0;
    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            maxValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            maxValue += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }
    return maxValue;
}

int main() {
    int i, n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item*)malloc(n*sizeof(Item));
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Items :\t\t");
    for(i = 0; i < n; i++)
	printf("Item%d\t",i+1);
    printf("\nWeights :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",items[i].weight);
    printf("\nValues :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",items[i].value);
    printf("\nV/W Ratio :\t");
    for(i = 0; i < n; i++)
        printf("%.2f\t",items[i].ratio);
    clock_t t = clock();
    float maxValue = fractionalKnapsack(items, n, capacity);
    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\nMaximum value in Knapsack : %.2f\n", maxValue);
    printf("Time taken : %f seconds\n", time);
    free(items);
    return 0;
}
