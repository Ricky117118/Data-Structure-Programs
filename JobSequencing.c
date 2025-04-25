#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Job {
    char id;       
    int deadline;  
    int profit;    
} Job;

void sortJobsByProfit(Job jobs[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}
void jobSequencing(Job jobs[], int n) {
    sortJobsByProfit(jobs, n);
    int i, j, maxDeadline = 0, maxProfit = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    int *slots = (int*)calloc(maxDeadline,sizeof(int));
    char *result = (char*)malloc(maxDeadline*sizeof(char));
    
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) { 
                result[j] = jobs[i].id;
		maxProfit += jobs[i].profit; 
                slots[j] = 1; 
                break;
            }
        }
    }

    printf("\nSelected jobs for maximum profit: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] == 1)
	    printf("%c ", result[i]);
    }
    printf("\nMaximum Profit : %d\n",maxProfit);
    free(slots);
    free(result);
}

int main() {
    Job jobs[] = {
        {'A', 2, 60},
        {'B', 3, 80},
        {'C', 1, 90},
        {'D', 2, 50},
        {'E', 3, 100},
    };
    int i, n = sizeof(jobs) / sizeof(jobs[0]);
    printf("Jobs :\t\t");
    for(i = 0; i < n; i++)
	printf("%c\t",jobs[i].id);
    printf("\nDeadline :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",jobs[i].deadline);
    printf("\nProfit :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",jobs[i].profit);
    clock_t t = clock();
    jobSequencing(jobs, n);
    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken : %f seconds\n", time);
    return 0;
}
