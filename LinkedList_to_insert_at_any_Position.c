#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
struct Node* createNode(int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
if(newNode==NULL){
printf("Memory allocation failed.\n");
exit(1);}
newNode->data=data;
newNode->next=NULL;
return newNode;}
void insertAtPosition(struct Node** head,int data,int position){
struct Node* newNode=createNode(data);
if(position==1||*head==NULL){
newNode->next=*head;
*head=newNode;
return;}
struct Node* temp=*head;
for(int i=1;i<position-1&&temp!=NULL;i++){
temp=temp->next;
}if(temp==NULL){
printf("\nOut of Bounds.\n");
free(newNode);
return;}
newNode->next=temp->next;
temp->next=newNode;}
void displayList(struct Node* head){
struct Node* temp=head;
while(temp!=NULL){
printf("%d->",temp->data);
temp=temp->next;}
printf("NULL\n");}
int main(){
struct Node* head=NULL;
int n,data,i,position;
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter value for node %d:",i+1);
scanf("%d",&data);
insertAtPosition(&head,data,i+1);}
printf("\nInitial linked list: ");
displayList(head);
printf("\nEnter a value to insert: ");
scanf("%d",&data);
printf("\nEnter the position to enter:");
scanf("%d",&position);
insertAtPosition(&head,data,position);
printf("\nUpdated linked list: ");
displayList(head);
return 0;}

