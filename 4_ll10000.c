// no of elemets greater than 10000
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}nodetype;

nodetype * addnode(nodetype *,int);
void check(nodetype *,int *);
int main(){
	nodetype *start=NULL,*current=NULL,*ptr,*new;
	int ch;
	while(1){
		printf("enter 1 to add node at last; 2 to get count of nodes;anything else terminate");
		scanf("%d",&ch);
		if(ch==1){
			if(start==NULL){
				start=(nodetype *)malloc(sizeof(nodetype));
				printf("enter 1st data ");
				scanf("%d",&start->data);
				start->next=NULL;
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
			int *ptr1,f;
			check(start,&f);
            printf("no. of nodes having data more than 10000 is %d\n",f);
		}
		else{
			break;
		}
	}
}
nodetype * addnode(nodetype *current,int n){
	nodetype *new=(nodetype *)malloc(sizeof(nodetype));
	new->data=n;
	new->next=NULL;
	current->next=new;
	return new;
}
void check(nodetype * start,int *ptr1){
	nodetype * ptr=start;
	int flag=0;
	if(ptr==NULL){
		printf("L.L is empty\n");
	}
	else{
		while (ptr!=NULL){
			if(ptr->data>=10000)
				flag++;
			ptr=ptr->next;
		}
	}
	*ptr1=flag;
}