#include <stdio.h>
#include <time.h>
typedef struct Activity {
    char name;    
    int start;    
    int finish;   
} Activity;

void activitySelection(Activity activities[], int n) {
    printf("\nSelected activities: ");
    int i = 0, j;
    printf("%c ", activities[i].name);

    for (j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("%c ", activities[j].name); 
            i = j;                             
        }
    }
}

int main() {
    Activity activities[] = {
        {'A', 1, 2},
        {'B', 3, 4},
        {'C', 0, 6},
        {'D', 5, 7},
        {'E', 8, 9},
        {'F', 5, 9}
    };
    int i, n = sizeof(activities) / sizeof(activities[0]);
    printf("Activity :\t");
    for(i = 0; i < n; i++)
        printf("%c\t",activities[i].name);
    printf("\nStart Time :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",activities[i].start);
    printf("\nFinish Time :\t");
    for(i = 0; i < n; i++)
        printf("%d\t",activities[i].finish);
    clock_t t = clock();
    activitySelection(activities, n);
    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTime taken : %f seconds\n",time); 
    return 0;
}

