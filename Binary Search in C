#include<stdio.h>

void bubblesort(int arr[],int n){
int i,j,temp;
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1]){
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;}}}
}

int binarySearch(int arr[],int n,int target){
int low=0,high=n-1;
while(low<=high){
int mid=low+(high-low)/2;
if(arr[mid]==target){
return mid;}
if(arr[mid]<target){
low=mid+1;
}else{
high=mid-1;}}
return -1;}

int main(){
int n,target,i,result;
printf("\nEnter the number of elements: ");
scanf("%d",&n);
int arr[n];
printf("\nEnter the elements: \n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);}
bubblesort(arr,n);
printf("\nSorted Array:\n");
for(i=0;i<n;i++){
printf("%d\t",arr[i]);}
printf("\nEnter Target Value: ");
scanf("%d",&target);
result=binarySearch(arr,n,target);
if(result!=-1){
printf("\nElement found at index %d\n",result);}
else{
printf("\nElement Not Found\n");
}return 0;}
