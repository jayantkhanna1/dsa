//Search for a node in bst

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}nodetype;
void addnode(nodetype *,int);
void search(nodetype *,int);
void inorder(nodetype *);
int flag=0;
int main(){
    nodetype *root=NULL;
    int ch;
    while (1)
    {
        printf("Enter 1 to enter data;2 for search;3 for inorder;anything else to exit");
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
            int key;
            printf("enter key");
            scanf("%d",&key);
            search(root,key);
            printf("\n");
            flag=0;
        }
        else if(ch==3){
            inorder(root);
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
void inorder(nodetype *root){
    if(root->left!=NULL)
        inorder(root->left);
    printf("%d ",root->data);
    if(root->right!=NULL)
        inorder(root->right);
}
void search(nodetype *root,int key){
    if(root->left!=NULL)
        search(root->left,key);
    if(root->data!=key)
        flag++;
    if(root->data==key){
        printf("key found at %d position",flag+1);
    }
    if(root->right!=NULL)
        search(root->right,key);
}
