
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
    int id;
	struct node* next;
}nodetype;

nodetype * last = NULL;
void addnode();
void check();
int deletenode();
int main()
{
    int ch;
    while(1){
        printf("enter 1 to add node at last; 2 to get timeslots;anything else terminate");
        scanf("%d",&ch);
        if(ch==1){
            addnode();
        }
        else if(ch==2){
            check();
        }
        else{
            break;
        }
    }
	return 0;
}
void addnode()
{
	int data,id;
	nodetype* temp;
	temp = (nodetype *)malloc(sizeof(nodetype));
	printf("Enter data \n");
	scanf("%d", &data);
    printf("Enter id \n");
	scanf("%d", &id);
	if (last == NULL) {
		temp->data = data;
		temp->next = temp;
        temp->id=id;
		last = temp;
	}
	else {
		temp->data = data;
		temp->next = last->next;
		last->next = temp;
        temp->id=id;
		last = temp;
	}
}
void check()
{
    int flag=0,flag1=0;
	struct node *temp, *position;
	temp = last->next;
	while(1){
		flag++;
        temp->data=temp->data-10;
        if(temp->data<=0){
            printf("Process %d ended in %d steps\n",temp->id,flag);
            flag1=deletenode();
        }
        if(flag1==1){
            break;
        }
        temp = temp->next;	
	}
}
int deletenode()
{
	struct node *temp, *position;
	temp = last->next;
	if (last == NULL)
		return 1;
	else {
		do{
            if(temp->next==last){
                if(temp->data<=0){
                    last=NULL;
                    free(temp);
                    return 1;
                }
            }
			else if(temp->next->data<=0){
                position = temp->next;
                temp->next = position->next;
                free(position);
                break;
            }
            else{

            }
			temp = temp->next;
		} while (temp != last->next);
        return 0;	
	}
}