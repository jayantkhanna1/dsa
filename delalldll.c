#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}nodetype;

nodetype * addnode(nodetype *,int);
void display(nodetype *,nodetype *);
nodetype * check(nodetype *,int);
int main(){
	nodetype *start=NULL,*current=NULL,*ptr,*new;
	int ch;
	while(1){
		printf("enter 1 to add node at last; 2 to Update;3 to display;anything else terminate");
		scanf("%d",&ch);
		if(ch==1){
			if(start==NULL){
				start=(nodetype *)malloc(sizeof(nodetype));
				printf("enter 1st data ");
				scanf("%d",&start->data);
				start->next=NULL;
				start->prev=NULL;
				current=start;
			}
			else{
				int n;
				printf("enter next data ");
				scanf("%d",&n);
				current=addnode(current,n);
			} 
		}
		else if(ch==2){
			int key;
			printf("enter key ");
			scanf("%d",&key);
			start=check(start,key);
		}
		else if(ch==3){
			display(start,ptr);
		}
		else{
			break;
		}
	}
}
nodetype * addnode(nodetype *current,int n){
	nodetype *new=(nodetype *)malloc(sizeof(nodetype));
	new->data=n;
	new->prev=current;
	new->next=NULL;
	current->next=new;
	return new;
}
nodetype * check(nodetype * start,int key){
	nodetype * ptr=start;
	if(ptr==NULL){
		printf("L.L is empty\n");
	}
    else if(ptr->data==key){
        return NULL;
    }
	else{
		while (ptr!=NULL){
			if(ptr->data==key){
					ptr->prev->next=NULL;
					break;
				}
				ptr=ptr->next;
		}
        return start;
	} 
}
void display(nodetype *start,nodetype *ptr){
	ptr=start;
	if(ptr==NULL){
		printf("L.L is empty\n");
	}
	else{
		while (ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n"); 
}
