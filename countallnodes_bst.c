#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}nodetype;

int flag=0;

void addnode(nodetype *,int);
void count(nodetype *);
int main()
{
    nodetype *root=NULL;
    int ch;
    while(1){
        printf("Enter 1 to enter data;2 to count nodes");
        scanf("%d",&ch);
        if(ch==1){
            if(root==NULL){
                root=(nodetype *)malloc(sizeof(nodetype));
                printf("Enter data 1 ");
                scanf("%d",&root->data);
                root->left=NULL;
                root->right=NULL;
            }
            else{
                int data;
                printf("Enter next data ");
                scanf("%d",&data);
                addnode(root,data);
            }
        }
        else if(ch==2){
            flag=0;
            count(root);
            printf("%d\n",flag);
        }
        else{
            break;
        }
    }

    return 0;
}

void addnode(nodetype *root,int data){
    nodetype *p;
    if(data>root->data){
        if(root->right==NULL){
            p=(nodetype *)malloc(sizeof(nodetype));
            p->data=data;
            p->right=NULL;
            p->left=NULL;
            root->right=p;
        }
        else{
            addnode(root->right,data);
        }
    }
    else{
        if(root->left==NULL){
            p=(nodetype *)malloc(sizeof(nodetype));
            p->data=data;
            p->right=NULL;
            p->left=NULL;
            root->left=p;
        }
        else{
            addnode(root->left,data);
        }
    }
}

void count(nodetype *root){
    if(root!=NULL){
        flag++;
        count(root->left);
        count(root->right);
    }
}