#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int findMax(int *arr, int n)
{
	int i,max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
int findMin(int *arr, int n)
{
        int i,min=arr[0];
        for(i=1;i<n;i++)
        {
                if(arr[i]<min)
                        min=arr[i];
        }
        return min;
}
int main()
{
	clock_t t;
	t=clock();
        int n,i;
	srand(time(NULL));
	printf("Enter the size of the array :\t");
        scanf("%d",&n);
        int *arr=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
                arr[i]=rand()%n;
        printf("Original Array :\t\t");
        for(i=0;i<n;i++)
                i?printf(", %d",arr[i]):printf("%d",arr[i]);
        int max=findMax(arr,n);
	int min=findMin(arr,n);
	t=clock()-t;
	double time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nMaximum Element:\t%d\n",max);
	printf("Minimum Element:\t%d\n",min);
        printf("Time taken :\t%f seconds\n",time_taken);
        free(arr);
        return 0;
}
