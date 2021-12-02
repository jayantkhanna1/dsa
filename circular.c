
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
        printf("enter 1 to add node at last; 2 to Update;3 to display;anything else terminate");
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
	int key, i = 1,flag=0;
	struct node *temp, *position;
	temp = last->next;
	if (last == NULL)
		printf("L.L is empty\n");
	else {
        
		printf("\n enter key : ");
		scanf("%d", &key);
		do{
			if(temp->next->data==key){
                flag++;
                position = temp->next;
                temp->next = position->next;
                free(position);
            }
			temp = temp->next;
		} while (temp != last->next);
		
	}
    if(flag==0){
        printf("No such element present\n");
    }
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