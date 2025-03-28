#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
struct Node* create_Node(int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
if(newNode==NULL){
printf("Memory allocation failed.\n");
exit(1);}
newNode->data=data;
newNode->next=NULL;
return newNode;}
void insertAtBeginning(struct Node** head,int data){
struct Node* newNode=create_Node(data);
newNode->next=*head;
*head=newNode;}
void displayList(struct Node* head){
struct Node* temp=head;
while(temp!=NULL){
printf("%d->",temp->data);
temp=temp->next;}
printf("NULL\n");}
int main(){
struct Node* head=NULL;
int n,data,i;
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter value for node %d:",i+1);
scanf("%d",&data);
insertAtBeginning(&head,data);}
printf("\nInitial linked list: ");
displayList(head);
printf("\nEnter a value to insert at the beginning: ");
scanf("%d",&data);
insertAtBeginning(&head,data);
printf("\nUpdated linked list: ");
displayList(head);
return 0;}
