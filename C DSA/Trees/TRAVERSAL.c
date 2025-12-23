#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *rigth;
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
printf("\nEnter the rigth child of %d",x);
newNode->rigth=createNode();
return newNode;
};

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->rigth);
    }
   
}

void postorder(struct node *root){
 
    if(root!=NULL){
     postorder(root->left);
     postorder(root->rigth);
        printf("%d",root->data);
    }
}

void inorder(struct node *root){
 
    if(root!=NULL){
     inorder(root->left);
    printf("%d",root->data);
     inorder(root->rigth);
    }
}

int main(){
    struct node *root=NULL;
    root=createNode();
    printf("\npreorder is :\n");
    preorder(root);
    printf("\nposteorder is :\n");
    postorder(root);
    printf("\ninorder is :\n");
    inorder(root);
}
// struct node *addroot(int data){
//     struct node *root1=createNode(data);
//     return root1;
// };

// struct node *addLeft(struct node *root,int data){
//     struct node *leftnode=createNode(data);
//     if(root!=NULL){
//     leftnode->data=data;
//     root->left=leftnode;
//     }
//     return leftnode;
// };
// struct node *addrigth(struct node *root,int data){
//     struct node *rigthnode=createNode(data);
//     if(root!=NULL){
//     rigthnode->data=data;
//     root->rigth=rigthnode;
//     }
//     return rigthnode;
// };

// struct node *makelR(struct node *root){
//     struct node *newroot=root->left;
//   return newroot;


// }
// struct node *makerR(struct node *root){
//     root->rigth=root;
//     return root;

// }

// int main(){
// struct node *root=NULL;
// int choice,data;
// do{
//     printf("\nEnter 1-to create a Root Node:");
//     printf("\nEnter 2-to create a Left Node:");
//     printf("\nEnter 3-to create a rigth Node:");
//     printf("\nEnter 4-to make left Node -Root:");
//     printf("\nEnter 5-to make rigth Node-Root:");
//     printf("\nEnter 6 for Pre-Order Traversal:");
//     printf("\nEnter 7Quit:");
//     scanf("%d",&choice);
//     switch(choice){
//         case 1:printf("\nEnter the value:");
//                 scanf("%d",&data);
//                 root=addroot(data);
//                 break;
//         case 2: printf("\nEnter the value:");
//                 scanf("%d",&data);
//                 addLeft(root,data);
//                 break;
//         case 3:printf("\nEnter the value:");
//                 scanf("%d",&data);
//                 addrigth(root,data);
//                 break;
//         case 4:root=makelR(root);
//                 break;
//         case 5:makerR(root);
//         case 6:preorder(root);
//                 break;
//                 break;
//         case 7:exit(0);
//         default:printf("Invalid Choice!");
//     }
//     }while(1);
// }

