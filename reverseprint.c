#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}nodetype;

nodetype * addnode(nodetype *,int);
void display(nodetype *);
int main(){
	nodetype *start=NULL,*ptr,*new;
	int ch;
	while(1){
		printf("Enter 1 to add node at start; 2 to Display;anything else terminate");
		scanf("%d",&ch);
		if(ch==1){
			if(start==NULL){
				start=(nodetype *)malloc(sizeof(nodetype));
				printf("enter 1st data ");
				scanf("%d",&start->data);
				start->next=NULL;
				
			}
			else{
				int n;
				printf("enter next data ");
				scanf("%d",&n);
				start=addnode(start,n);
			}
		}
		else if(ch==2){
			display(start);
		}
		else{
			break;
		}
	}
}
nodetype * addnode(nodetype *start,int n){
    nodetype *new=(nodetype *)malloc(sizeof(nodetype));
    new->data=n;
    new->next=start;
    return new;;
}
void display(nodetype *start){
	if(start!=NULL){
		display(start->next);
		printf("%d ",start->data);
	}
	printf("\n"); 
}