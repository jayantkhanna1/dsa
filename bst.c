#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}nodetype;
void addnode(nodetype *,int);
void preorder(nodetype *);
void inorder(nodetype *);
void postorder(nodetype *);
int main(){
    nodetype *root=NULL;
    int ch;
    while (1)
    {
        printf("Enter 1 to enter data; 2 for preorder;3 for inorder;4 for postorder;anything else to exit");
        scanf("%d",&ch);
        if(ch==1){
            if(root==NULL){
                root=(nodetype *)malloc(sizeof(nodetype));
                printf("enter 1st data");
                scanf("%d",&root->data);
                root->left=NULL;
                root->right=NULL;
            }
            else{
                int data;
                printf("enter next data");
                scanf("%d",&data);
                addnode(root,data);
            }
        }
        else if(ch==2){
            preorder(root);
            printf("\n");
        }
        else if(ch==3){
            inorder(root);
            printf("\n");
        }
        else if(ch==4){
            postorder(root);
            printf("\n");
        }
        else{
            break;
        }
    } 
}
void addnode(nodetype *root,int data){
    nodetype *p=NULL;
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
void preorder(nodetype *root){
    printf("%d ",root->data);
    if(root->left!=NULL){
        preorder(root->left);
    }
    if(root->right!=NULL){
        preorder(root->right);
    }
}
void inorder(nodetype *root){
    if(root->left!=NULL){
        inorder(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL){
        inorder(root->right);
    }
}
void postorder(nodetype *root){
    if(root->left!=NULL){
        postorder(root->left);
    }
    if(root->right!=NULL){
        postorder(root->right);
    }
    printf("%d ",root->data);
}