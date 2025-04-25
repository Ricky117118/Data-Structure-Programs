#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* prev;
struct Node* next;};
struct Node* createNode(int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
return newNode;}
    void insertAtPosition(struct Node** head,int data,int position){
struct Node* newNode=createNode(data);
newNode->data=data;
if(position==1){
newNode->next=*head;
newNode->prev=NULL;
if(*head!=NULL){
(*head)->prev=newNode;}
*head=newNode;
return;}
struct Node* temp=*head;
for(int i=1;i<position-1 && temp!=NULL;i++){
temp=temp->next;}
if(temp==NULL){
printf("Out of Bounds\n");
return;}
newNode->next=temp->next;
newNode->prev=temp;
if(temp->next!=NULL){
temp->next->prev=newNode;}
temp->next=newNode;}
   void display(struct Node* head){
struct Node* temp=head;
printf("\nList:");
printf("NULL<->");
while(temp!=NULL){
printf("%d<->",temp->data);
temp=temp->next;
}printf("NULL");}
int main(){
struct Node* head=NULL;
int n,i,value,position;
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter value for node %d:",i+1);
scanf("%d",&value);
insertAtPosition(&head,value,i+1);}
printf("\nInitial list:");
display(head);
printf("\nEnter the value to insert:");
scanf("%d",&value);
printf("\nEnter the position to insert value:");
scanf("%d",&position);
insertAtPosition(&head,value,position);
printf("\nUpdated list:");
display(head);
return 0;}
