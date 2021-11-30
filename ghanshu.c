#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}nodetype;

nodetype * addatlast(nodetype *,int);
void display(nodetype *,nodetype *);
nodetype *  check(nodetype *,nodetype *,int);
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
                current=start;
            }
            else{
                int n;
                printf("enter next data ");
                scanf("%d",&n);
                current=addatlast(current,n);
            }   
        }
        else if(ch==2){
                int key;
                printf("enter key");
                scanf("%d",&key);
                current=check(start,current,key);
        }
        else if(ch==3){
            display(start,ptr);
        }
        else{
            break;
        }
    }
}
nodetype * addatlast(nodetype *current,int n){
    nodetype *new=(nodetype *)malloc(sizeof(nodetype));
    new->data=n;
    new->next=NULL;
    current->next=new;
    return new;
}
nodetype * check(nodetype * start,nodetype * current,int key){
    nodetype * ptr=start;
    nodetype *temp=current;
    int flag=0,flag1=0;
    if(ptr==NULL){
        printf("L.L is empty");
    }
    else{
        while (ptr->next!=NULL){
            if(ptr->next->data==key){
                flag++;
                if(ptr->next->next=NULL){
                    printf("hello");
                    flag1=1;
                    temp=ptr;
                    ptr->next=NULL;
                }
                else{
                    printf("world");
                    ptr->next=ptr->next->next;
                }
                break;
            }
            ptr=ptr->next;
        }
    }
    if(flag==0){
        printf("no such value found");
    }
    if(flag1==1){
        return temp;
    }
    if(flag1==0){
        return current;
    }
    printf("\n");  
}
void display(nodetype *start,nodetype *ptr){
    ptr=start;
    if(ptr==NULL){
        printf("L.L is empty");
    }
    else{
        while (ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");  
}