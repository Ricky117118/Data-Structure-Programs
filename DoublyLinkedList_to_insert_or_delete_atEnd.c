#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* prev;
struct Node* next;};

void insertAtEnd(struct Node** head,int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
if(*head==NULL){
newNode->next=newNode->prev=newNode;
*head=newNode;
return;}
struct Node* last=(*head)->prev;
newNode->next=*head;
(*head)->prev=newNode;
newNode->prev=last;
last->next=newNode;}

void deleteAtEnd(struct Node** head){
if(*head==NULL){
printf("List is empty\n");
return;}
if((*head)->next==*head){
free(*head);
*head=NULL;
return;
}struct Node* last=(*head)->prev;
struct Node* secondLast=last->prev;
secondLast->next=*head;
(*head)->prev=secondLast;
free(last);}

void display(struct Node* head){
if(head==NULL){
printf("\nList is empty\n");
return;}
struct Node* temp=head;
printf("\nList:");
printf("Head<->");
do{
printf("%d<->",temp->data);
temp=temp->next;
}while(temp!=head);
printf("Head\n");}

int main(){
struct Node* head=NULL;
int choice,value;
while(1){
printf("\nEnter 1 to delete from end,2 to insert at end,any other number to exit:");
scanf("%d",&choice);
if(choice==1){
printf("\nDeleting from end...\n");
deleteAtEnd(&head);
}else if(choice==2){
printf("\nEnter value to insert:");
scanf("%d",&value);
insertAtEnd(&head,value);}
else{
break;}
display(head);}
printf("\nExiting\n");

return 0;}

