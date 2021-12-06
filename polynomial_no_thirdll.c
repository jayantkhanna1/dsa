#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int poly;
    struct node *next;
}nodetype;

nodetype *addnode(nodetype *,int,int);
void display(nodetype *);
void check(nodetype *,nodetype *);
int main()
{
    int ch;
    nodetype *start1=NULL,*start2=NULL,*current1=NULL,*current2=NULL;
    while(1){
        printf("enter 1 to add polynomial 1; 2 for 2nd polynomial;anything else to get answer");
        scanf("%d",&ch);
        if(ch==1){
            if(start1==NULL){
                start1=(nodetype*)malloc(sizeof(nodetype));
                printf("enter 1st data");
                scanf("%d",&start1->data);
                printf("enter 1st poly");
                scanf("%d",&start1->poly);
                start1->next=NULL;
                current1=start1;
            }
            else{
                int data,poly;
                printf("enter data");
                scanf("%d",&data);
                printf("enter poly");
                scanf("%d",&poly);
                current1=addnode(current1,data,poly);
            }
        }
        else if(ch==2){
            if(start2==NULL){
                start2=(nodetype*)malloc(sizeof(nodetype));
                printf("enter 1st data");
                scanf("%d",&start2->data);
                printf("enter 1st poly");
                scanf("%d",&start2->poly);
                start2->next=NULL;
                current2=start2;
            }
            else{
                int data,poly;
                printf("enter data");
                scanf("%d",&data);
                printf("enter poly");
                scanf("%d",&poly);
                current2=addnode(current2,data,poly);
            }
        }
        else{
            check(start1,start2);
            break;
        }
    }
    return 0;
}
nodetype *addnode(nodetype *current,int data,int poly){
    nodetype *new=(nodetype*)malloc(sizeof(nodetype));
    new->data=data;
    new->poly=poly;
    new->next=NULL;
    current->next=new;
    return new;
}
void display(nodetype *start){
    while(start!=NULL){
        printf("%dx%d ",start->data,start->poly);
        start=start->next;
    }
    printf("\n");
}
void check(nodetype *start1,nodetype *start2){
    nodetype *ptr1=start1,*ptr2=start2;
    while(ptr1!=NULL){
       while(ptr2!=NULL){
            if(ptr1->poly==ptr2->poly){
                ptr1->data=ptr1->data+ptr2->data;
                ptr2->data=-99909;
            }
            ptr2=ptr2->next;
       }
       ptr2=start2;
       ptr1=ptr1->next;
    }
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL){
         printf("%dx%d ",ptr1->data,ptr1->poly);
         ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        if(ptr2->data!=-99909)
            printf("%dx%d ",ptr2->data,ptr2->poly);
        ptr2=ptr2->next;
    }
    printf("\n");
}