#include <stdio.h>
#include <time.h>

//min heap

void heapify(int arr[], int n, int i)
{
    int temp, smallest, left_index, right_index;
    smallest = i;
    
    right_index = 2 * i + 2;
    
    left_index = 2 * i + 1;
    if (left_index < n && arr[left_index] < arr[smallest])
        smallest = left_index;
    if (right_index < n && arr[right_index] < arr[smallest])
        smallest = right_index;
    if (smallest != i) {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void heapsort(int arr[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}



void insert(int arr[], int *n, int element) {
    int i = (*n)++;
    arr[i] = element;
    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
void deleteAtPosition(int arr[], int *n, int position) {
    if (position >= *n || position < 0) {
        printf("Invalid position!\n");
        return;
    }
    arr[position] = arr[--(*n)];
    heapify(arr, *n, position);
}


int main()
{
    int i, n, choice, elementToInsert, positionToDelete;
    printf("Enter the value of n= ");
    scanf("%d", &n);
    int arr[50];
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapsort(arr, n);
    printf("Array after performing heap sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nThe Time=%f\n", cpu_time_used);
 while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element at a given position\n");
        printf("Any other number to quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            // Insert an element
            printf("Enter the element to insert: ");
            scanf("%d", &elementToInsert);
            insert(arr, &n, elementToInsert);
            printf("Array after insertion: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
         heapsort(arr, n);
    printf("\nArray after performing heap sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

        }
        else if (choice == 2) {

            printf("Enter the position to delete (0-based index): ");
            scanf("%d", &positionToDelete);
            deleteAtPosition(arr, &n, positionToDelete);
            printf("\nArray after deletion: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
         heapsort(arr, n);
    printf("\nArray after performing heap sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

        }
        else {
            break;
        }
    }
 return 0;
}

