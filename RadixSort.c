#include<stdio.h>
int getMax(int arr[],int n){
int max=arr[0];
for(int i=1;i<n;i++){
if(arr[i]>max){
max=arr[i];}}
return max;}
void countingSort(int arr[],int n,int exp){
int output[n];
int count[10]={0};
for(int i=0;i<n;i++){
int digit=(arr[i]/exp)%10;
count[digit]++;}
for(int i=1;i<10;i++){
count[i]+=count[i-1];}
for(int i=n-1;i>=0;i--){
int digit=(arr[i]/exp)%10;
output[count[digit]-1]=arr[i];
count[digit]--;}
for(int i=0;i<n;i++){
arr[i]=output[i];}}
void radixSort(int arr[],int n){
int max=getMax(arr,n);
for(int exp=1;max/exp>0;exp*=10){
countingSort(arr,n,exp);}}
int main(){
int i,n,arr[100];
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("\nEnter the elements:\n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);}
radixSort(arr,n);
printf("\nSorted Array:\t");
for(i=0;i<n;i++){
printf("%d\t",arr[i]);
}
return 0;}
