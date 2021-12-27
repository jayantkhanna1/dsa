//delete nodes from binary search tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}nodetype;
void addnode(nodetype *,int);
nodetype * delete(nodetype *,int);
nodetype * nextinorder(nodetype *);
void inorder(nodetype *);
int main()
{
    nodetype *root=NULL;
    int ch;
    while(1){
        printf("Enter 1 to enter data;2 to see nodes;3 to delete node");
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
            inorder(root);
            printf("\n");
        }
        else if(ch==3){
            int data;
            printf("Enter key to be deleted ");
            scanf("%d",&data);
            root=delete(root,data);
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
void inorder(nodetype *root){
    if(root->left!=NULL){
        inorder(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL){
        inorder(root->right);
    }
}
nodetype* nextinorder(nodetype* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
nodetype* delete(nodetype* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = nextinorder(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}