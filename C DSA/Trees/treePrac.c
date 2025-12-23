#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node *left;
    struct node *right;
}tree;

tree *createNode(){
    int x;
    tree *newNode=(tree *)malloc(sizeof(tree));
    printf("Enter the data(-1 for no data)\n" );
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newNode->info=x;
    printf("Enter the left child of %d\n",x);
    newNode->left=createNode();
    printf("Enter the right child of %d\n",x);
    newNode->right=createNode();
    return newNode;
};

//deleting a node

tree *inorderpredeccesor(tree *root){

    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
return root;
}
tree *deleteNode(tree *root,int value){
        tree *iPre;
if(root==NULL){
    return NULL;
}
if(root->left==NULL&&root->right==NULL){
    free(root);
    return NULL;
}
if(value<root->info){
    root->left=deleteNode(root->left,value);
}
else if(value>root->info){
    root->right=deleteNode(root->right,value);
}
else{
iPre=inorderpredeccesor(root);
root->info=iPre->info;
deleteNode(root->left,iPre->info);
}
return root;
}
tree *search(tree *root,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->info==value){
        return root;
    }
    if(value<root->info){
         return search(root->left,value);
    }
    if(value>root->info){
        return search(root->right,value);
    }
};
void inorder(tree *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->info);
        inorder(root->right);
    }
}
int main(){
    tree *root=NULL;
    int choice,value;
    do{
    printf("Enter:\n");
    printf("1-Create a Tree\n");
    printf("2-Delete a value\n");
    printf("3-Search a Value\n");

    printf("4-Print");
    scanf("%d",&choice);
    switch(choice){
        case 1:root=createNode();
        break;
        case 2:printf("Enter the value to delete:");
        scanf("%d",&value);
        deleteNode(root,value);
        break;
        case 3:printf("Enter the value to delete:");
        scanf("%d",&value);
  
        tree *n=search(root,value);
            if(n!=NULL){
                printf("Element found:%d",n->info);
            }
            else{
                printf("Element not found!");
            }
           break;
 
        case 4:inorder(root);
        break;
        default:printf("Invalid Choice!!!");
        exit(0);
    }
}while(1);}