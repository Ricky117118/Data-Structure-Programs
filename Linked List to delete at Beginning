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
void deleteFirstNode(struct Node** head){
if(*head==NULL){
printf("List Empty. No nodes to delete.\n");
return;}
struct Node* temp=*head;
*head=(*head)->next;
free(temp);
printf("\nFirst node deleted.\n");
}
void insertAtEnd(struct Node** head,int data){
struct Node* newNode=createNode(data);
if(*head==NULL){
*head=newNode;
return;}
struct Node* temp=*head;
while(temp->next!=NULL){
temp=temp->next;}
temp->next=newNode;}
void displayList(struct Node* head){
struct Node* temp=head;
if(temp==NULL){
printf("\nList is empty.\n");
return;}
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
insertAtEnd(&head,data);}
printf("\nInitial linked list: ");
displayList(head);
deleteFirstNode(&head);
printf("\nlinked list after deletion: ");
displayList(head);
return 0;}

