#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;}

void heapify(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;

if(left<n&&arr[left]>arr[largest])
largest=left;

if(right<n&&arr[right]>arr[largest])
largest=right;

if(largest!=i){
swap(&arr[i],&arr[largest]);
heapify(arr,n,largest);}}

void heapSort(int arr[],int n){
for(int i=n/2;i>=0;i--)
heapify(arr,n,i);
for(int i=n-1;i>0;i--){
swap(&arr[0],&arr[i]);
heapify(arr,i,0);}}

void printArray(int arr[],int n){
for(int i=0;i<n;++i)
printf("%d\t",arr[i]);
printf("\n");}

int main(){
int n,i;
clock_t t;
t=clock();
printf("\nEnter the number of elements: ");
scanf("%d",&n);
int *arr=(int *)malloc(n*sizeof(int));
printf("\nEnter the elements: \n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);}
printf("\nOriginal Array:\n");
printArray(arr,n);
heapSort(arr,n);
t=clock()-t;
double time_taken=((double)t)/CLOCKS_PER_SEC;
printf("\nSorted Array:\n");
printArray(arr,n);
printf("\nTime taken to execute: %f seconds\n",time_taken);
free(arr);
return 0;}


