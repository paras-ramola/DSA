#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(){
int x;
struct node *newNode;
newNode=(struct node *) malloc(sizeof(struct node));
printf("\nEnter the data (-1 for No data):");
scanf("%d",&x);
if(x==-1){
    return 0;
}
newNode->data=x;
printf("\nEnter the left child of %d",x);
newNode->left=createNode();
printf("\nEnter the right child of %d",x);
newNode->right=createNode();
return newNode;
};

// Searching a Node
struct node *searchNode(struct node *root,int key){
if(root==NULL){
    return NULL;
}
if(key==root->data){
    return root;
}
else if(key<root->data){
   return searchNode(root->left,key);
}
else{
    return searchNode(root->right,key);
}
};

//Delete a Node
struct node *inorderPredecessor(struct node *root){//inorderPredeccor->left subtrree ka rightmost node
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;

}

struct node *deleteNode(struct node*root,int value){
    struct node *iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL &&root->right==NULL){
        free(root);
        return NULL;// The return NULL; statement in this particular case is intended to inform the parent of the current node that its child has been deleted, and the pointer to that child should be set to NULL,otherwise the pointer will still point to that menory adress that has been deleted
    }
    if(value<root->data){
        root->left=deleteNode(root->left,value);//It ensures that the left subtree of the current node is correctly updated after the deletion operation.
    }
    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    else{//if value to be deleted is the Root node
        iPre=inorderPredecessor(root);
        root->data=iPre->data;
        deleteNode(root->left,iPre->data);
    }
    return root;
}

//Number of leaf nodes
int leafCount(struct node *root){
    int count;
    if(root==NULL){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return 1;
    }
    else {
        return leafCount(root->left)+ leafCount(root->right);
    }
    
};

//height of tree-no. of edges from root node to the most distant leaf node
int height(struct node *root){
    int h;
    if(root==NULL){
        return -1;//counting edges
    }
    int left= height(root->left);
    int right=height(root->right);
    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}

//count total number of nodes from right side of root node
int countRightNode(struct node *root){
    if(root==NULL){
        return 0;
    }
    int cnt=countRightNode(root->right);
    if(root->right!=NULL){
        return cnt+1;
    }
}

//Kth largest element in BSt
int largestNode(struct node *root){
    if(root==NULL){
        return 0;
    }
    int max=0;
    int l=largestNode(root->left);
    int r=largestNode(root->right);
    if(l>max){
        max=l;
    }
    else{
        max=r;
    }
    return max;
}

void inorder(struct node *root){
    if(root!=NULL){
     inorder(root->left);
    printf("%d\t",root->data);
     inorder(root->right);
    }
}


int main(){
    struct node *root;
    root=NULL;
 
    do{
       int choice,val,key;
    printf("\nEnter 1- to create a tree");
    printf("\nEnter 2- Inorder");
    printf("\nEnter 3- Delete a Node");
    printf("\nEnter 4-Search a Node");
    printf("\nEnter 5-Count Num of leaf nodes");
    printf("\nEnter 6-Height of Tree");
    printf("\nEnter 7-Count the number of node in right side");
    printf("\nEnter 8-Largest Node");
    // printf("\nEnter 3- Insert a Node");
    printf("\nEnter 9- Quit");
    // printf("\nEnter 1- to create a tree");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:root=createNode();
        break;
    case 2:printf("\ninorder is :\n");
            inorder(root);
        break;
    // case 3:insert(root,7);
    //         break;
    case 3:printf("\nEnter the value to delete:");
            scanf("%d",&val);
    deleteNode(root,val);
    printf("\nValue Delted succesfully");
            break;
    case 4:printf("\nEnter a value to search");
            scanf("%d",&key);
            struct node *n=searchNode(root,key);
            if(n!=NULL){
                printf("Element found:%d",n->data);
            }
            else{
                printf("Element not found!");
            }
           break;
    case 5: printf("\nnumber of leaf nodes are: %d",leafCount(root));
            break;
    case 6:printf("\nThe height of tree is :%d",height(root));
            break;
    case 7:printf("\nThe num of right node is: %d",countRightNode(root));
            break;
    case 8:printf("\nThe Largest number is: %d",largestNode(root));
            break;
    case 9:exit(1);
            break;
    default:printf("invalid Choice");
        break;
    }

}while(1);
}