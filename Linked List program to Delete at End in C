#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* prev;
struct Node* next;};

void insertAtEnd(struct Node** head,int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
if(*head==NULL){
newNode->prev=NULL;
*head=newNode;
return;}
struct Node* temp=*head;
while(temp->next!=NULL){
temp=temp->next;}
temp->next=newNode;
newNode->prev=temp;}

void deleteAtEnd(struct Node** head){
if(*head==NULL){
printf("List is empty\n");
return;}
struct Node* temp=*head;
if(temp->next==NULL){
free(temp);
*head=NULL;
return;
}while(temp->next!=NULL){
temp=temp->next;}
temp->prev->next=NULL;
free(temp);}

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
int n,i,value;
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter value for node %d:",i+1);
scanf("%d",&value);
insertAtEnd(&head,value);}
printf("\nInitial list:");
display(head);
deleteAtEnd(&head);
printf("\nNew List:");
display(head);
return 0;}
