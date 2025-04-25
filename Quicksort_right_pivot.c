#include<stdio.h>
#include<time.h>

//rightmost pivot
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;}

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++){
	if(arr[j]<=pivot){
	i++;
	swap(&arr[i],&arr[j]);}}
 swap(&arr[i+1],&arr[high]);
return (i+1);}

void quickSort(int arr[],int low,int high){
	if(low<high){
	int pi=partition(arr,low,high);
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);}}

int main(){
	int n,i,arr[100];
	clock_t t;
	t=clock();

	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++){
	scanf("%d",&arr[i]);}
	quickSort(arr,0,n-1);
t=clock()-t;
double time_taken=((double)t)/CLOCKS_PER_SEC;

	printf("\nSorted Array:\t");
	for(i=0;i<n;i++){
	printf("%d\t",arr[i]);}
printf("\nTime taken %f seconds to execute.",time_taken);

	return 0;}


