#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node *next;
	int id;
	int cost;
}nodetype;
nodetype * addnode(nodetype *,int,int);
void view(nodetype *);
int main(){
    printf("enter number of nodes");
    int n;
    scanf("%d",&n);
    nodetype *root[n],*current[n];
    for (int i=0;i<n;i++){
        root[i]=NULL;
        current[i]=NULL;
    }
    int ch;
    while (1)
    {
        printf("Enter 1 to enter data;2 to view;anything else to exit");
        scanf("%d",&ch);
        if(ch==1){
                printf("Enter which nodes connection are you making");
                int node;
                scanf("%d",&node);
            if(root[node]==NULL){
                root[node]=(nodetype *)malloc(sizeof(nodetype));
                printf("enter node to which connection is being made");
                scanf("%d",&root[node]->id);
                printf("enter cost");
                scanf("%d",&root[node]->cost);
                root[node]->next=NULL;
                current[node]=root[node];
            }
            else{
                int id,cost;
                printf("enter node to which connection is being made");
                scanf("%d",&id);
                printf("enter cost");
                scanf("%d",&cost);
                current[node]=addnode(current[node],id,cost);
            }
        }
        else if(ch==2){
            int node;
            printf("enter node you wanna view");
            scanf("%d",&node);
            view(root[node]);
            printf("\n");
        }
        else{
            break;
        }
    }
}
nodetype * addnode(nodetype *root,int id,int cost){
    nodetype *p=NULL;
    p=(nodetype *)malloc(sizeof(nodetype));
    p->next=NULL;
    p->id=id;
    p->cost=cost;
    root->next=p;
    return p;
}
void view(nodetype *root){
    while(root!=NULL){
        printf("connection to %d with weight %d\n",root->id,root->cost);
        root=root->next;
    }
}
