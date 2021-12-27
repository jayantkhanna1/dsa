//count number of nodes in circular nodes
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}nodetype;

nodetype * last = NULL;
void addnode();
void display();
void check();
int main()
{
    int ch;
    while(1){
        printf("enter 1 to add node at last; 2 to Count;3 to display;anything else terminate");
        scanf("%d",&ch);
        if(ch==1){
            addnode();
        }
        else if(ch==2){
            check();
        }
        else if(ch==3){
            display();
        }
        else{
            break;
        }
    }
	return 0;
}
void addnode()
{
	int data;
	nodetype* temp;
	temp = (nodetype *)malloc(sizeof(nodetype));
	printf("Enter data \n");
	scanf("%d", &data);
	if (last == NULL) {
		temp->data = data;
		temp->next = temp;
		last = temp;
	}
	else {
		temp->data = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}
void check()
{
    int flag=0;
	struct node *temp;
	temp = last->next;
	if (last == NULL)
		printf("L.L is empty\n");
	else {
		do{
            flag++;
			temp = temp->next;
		} while (temp != last->next);
		
	}
    printf("Number of elements in LL is:%d\n",flag);
}

void display()
{
	if (last == NULL)
		printf("L.L is empty\n");
	else {
		struct node* temp;
		temp = last->next;
		do{
			printf("Data = %d\n", temp->data);
			temp = temp->next;
		}while (temp != last->next);
	}
}