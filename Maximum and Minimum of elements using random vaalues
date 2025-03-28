#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct MinMax{
	int min;
	int max;};

struct MinMax findMinMax(int arr[],int low,int high){
	struct MinMax result,left,right;
	int mid;
if(low==high){
	result.min=arr[low];
	result.max=arr[low];
	return result;}
if(high==low+1){
if(arr[low]<arr[high]){
result.min=arr[low];
result.max=arr[high];}
else{
result.min=arr[high];
result.max=arr[low];}
return result;}
mid=low+(high-low)/2;
left=findMinMax(arr,low,mid);
right=findMinMax(arr,mid+1,high);
result.min=(left.min<right.min)?left.min:right.min;
result.max=(left.max>right.max)?left.max:right.max;
return result;}

int main(){
int n,i;
printf("Enter the number of elements: ");
scanf("%d",&n);

int arr[n];
clock_t t;
t=clock();
srand(time(NULL));
for(i=0;i<n;i++){
arr[i]=rand()%n;}
struct MinMax result=findMinMax(arr,0,n-1);
printf("\nMinimum element:%d\n",result.min);
printf("\nMaximum element:%d\n",result.max);
t=clock()-t;
double time_taken=((double)t)/CLOCKS_PER_SEC;

printf("\nTime taken %f seconds to execute.",time_taken);
return 0;}

