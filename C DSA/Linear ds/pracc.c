#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

// Given a sorted doubly linked list and a value to insert, write a function to insert the value in sorted way
// typedef struct node{
//     int info;
//     struct node *next;
//     struct node *prev;
// }dll;

// dll *createNode(int info){
// dll *newNode=(dll *)malloc(sizeof(dll));
// if(newNode==NULL){
//     printf("Menory not Available!!\n");
// }
// else{
// newNode->info=info;
// newNode->next=NULL;
// newNode->prev=NULL;
// }
// return newNode;
// };
// void display(dll *ptr){
// while(ptr!=NULL){
//     printf("Element:%d\n",ptr->info);
//     ptr=ptr->next;
// }
// }

// dll *insertSorted(dll *head,int info){
//     dll *newNode=createNode(info);
// if(head==NULL){
// head=newNode;
// newNode->next=NULL;
// newNode->info=info;
// return head;
// }
// //if newNode is less than head

// else if(newNode->info<head->info){
//     head->prev=newNode;
//     newNode->next=head;
//     head=newNode;
// }
//if newNode is more than head and newNode is more then temp
// else{dll *temp=head;
// while(newNode->info>temp->info){
//     if(temp->next==NULL){
//         temp->next=newNode;
//         newNode->prev=temp;
//         newNode->next=NULL;
//         return head;
//     }
// temp=temp->next;//jabtak newnode ki value bdi h temp se
// }
// temp->prev->next=newNode;
// newNode->prev=temp->prev;
// newNode->next=temp;
// temp->prev=newNode;
// temp->info=info;
// }
// return head;
// }


// int main(){
//     dll *head=NULL;
//     int choice,value;
//     do{
//         printf("Enter:1-insertion,2-Display\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:printf("Enter the value to insert:");
//             scanf("%d",&value);
//             head=insertSorted(head,value);
//             break;
//             case 2:display(head);
//             break;
//             default:printf("Invalid Choice");
//             exit(0);
//         }
//     }while(1);
//     return 0;
// }
// ********************************************************************************
//remove duplicate from double linked list
//reverse double linked list

// typedef struct node{
//     int info;
//     struct node *next;
//     struct node *prev;
// }dll;

// dll *createNode(int info){
// dll *newNode=(dll *)malloc(sizeof(dll));
// if(newNode==NULL){
//     printf("Menory not Available!!\n");
// }
// else{
// newNode->info=info;
// newNode->next=NULL;
// newNode->prev=NULL;
// }
// return newNode;
// };
// void display(dll *ptr){
// while(ptr!=NULL){
//     printf("Element:%d\n",ptr->info);
//     ptr=ptr->next;
// }
// }
// dll *insertNode(dll *head,int info){
//     dll *newNode=createNode(info);
//     if(head==NULL){
//         newNode->info=info;
//         newNode->next=NULL;
//         newNode->prev=NULL;
//         head=newNode;
//     }
//     else{
//         dll *ptr=head;
//         while(ptr->next!=NULL){
//             ptr=ptr->next;
//         }
//         newNode->next=NULL;
//        ptr->next=newNode;
//        newNode->prev=ptr;
//         newNode->info=info;
//     }
//     return head;
// };
// void reverse(dll *head){
//     dll *ptr=head;
//     dll *temp=ptr->next;

//     ptr->next=NULL;
//     ptr->prev=temp;
//     while(temp!=NULL){
//       temp->prev=temp->next;
//       temp->next=ptr;
//       ptr=temp;//move to adress of temp(ptr->next)
//       temp=temp->prev;//temp ke prev me temp->next ka adress store h
//     }
//   head=ptr;
// display(head);
// }
// void removeDuplicate(dll *head){
//     dll *ptr1,*ptr2,*dup;
//     ptr1=head;
//     while(ptr1!=NULL&&ptr1->next!=NULL){
//         ptr2=ptr1;
//         while(ptr2->next!=NULL){
//             if(ptr1->info==ptr2->next->info){
//                 dup=ptr2->next;
//                 ptr2->next=ptr2->next->next;
//                 free(dup);
//             }
//             else{
//                 ptr2=ptr2->next;
//             }
//         }
//         ptr1=ptr1->next;
//     }
//     display(head);//alag se display krne ki jarrurat nhi pdegi
// }
// int main(){
//     dll *head=NULL;
//     int choice,value;
//     do{
//         printf("Enter:1-insertion,2-Remove Duplicate,3-Reverse,4-Display\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:printf("Enter the value to insert:");
//             scanf("%d",&value);
//             head=insertNode(head,value);
//             break;
//             case 2:removeDuplicate(head);
//             break;
//             case 3:reverse(head);
//             break;
//             case 4:display(head);
//             break;
//             default:printf("Invalid Choice");
//             exit(0);
//         }
//     }while(1);
//     return 0;
// }

//***************************************************************************************

//count no of nodes on circular linked list

// typedef struct node{
//     int info;
//     struct node *next;
// }cll;

// cll *createNode(int info){
//     cll *newNode=(cll*)malloc(sizeof(cll));
// if(newNode==NULL){
//     printf("Memory not available");
// }
// else{
//     newNode->info=info;
//     newNode->next=NULL;
//     return newNode;
// }
// };

// void display(cll *head){
//     cll *ptr=head;
//     do{
//         printf("Element:%d\n",ptr->info);
//         ptr=ptr->next;
//     }
//     while(ptr!=head);
// }

// cll *insert(cll *head,int info){
//     cll *newNode=createNode(info);
//     if(head==NULL){
//         newNode->info=info;
//         newNode->next=newNode;
//         head=newNode;
//     }
//     else{
//         cll *ptr=head->next;
//         while(ptr->next!=head){
//             ptr=ptr->next;
//         }
//         newNode->next=head;
//         ptr->next=newNode;
//         newNode->info=info;
//     }
//     return head;
// };
// int countNode(cll *head){
//     int count=0;
//     if(head==NULL){
//         return 0;
//     }
//     else{
//     cll *ptr=head;
//     do{
//         count++;
//         ptr=ptr->next;
//     }while(ptr!=head);
//     return count;}

// }

// int main(){
//     cll *head= NULL;
//     int choice ,info;
//     do{
//         printf("Enter: \n");
//         printf("1-Insertion at Beggining \n");
//         printf("2-COUNT\n");
//         printf("3-DISPLAY\n");
//         printf("Enter Your Choice\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//             printf("\nEnter the data :");
//             scanf("%d",&info);
//             head=insert(head,info);
//             break;
//             case 2:printf("NUmber of node in the Linked list are :%d\n",countNode(head));
//             case 3:display(head);
//                 break;
//             default:printf("INVALID CHOICE");
//             exit(0);}}while(1);}

//reverse a linked list 

typedef struct node{
    int info;
    struct node *next;
}ll;

ll *createNode(int info){
ll *newNode=(ll *)malloc(sizeof(ll));
if(newNode==NULL){
    printf("Menory not Available!!\n");
}
else{
newNode->info=info;
newNode->next=NULL;
}
return newNode;
};
void display(ll *ptr){
while(ptr!=NULL){
    printf("Element:%d\n",ptr->info);
    ptr=ptr->next;
}
}
 ll *insertNode(ll *head,int info){
    ll *newNode=createNode(info);
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        newNode->info=info;
        return head;
    }
    else{
        ll *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;
        newNode->info=info;
    }
    return head;
 };
 void reverse(ll *head){
  ll *prevNode,*currNode,*nextNode;
  prevNode=NULL;
  currNode=head;
    while(nextNode!=NULL){
        // nextNode=nextNode->next;
        // currNode->next=prevNode;
        // prevNode=currNode;
        // currNode=nextNode;
        nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }
    head=prevNode;//bcz nextNode=0,and currNode=nextNode
display(head);
 }
ll * reverseK(ll *head,int k){
    ll *prevNode=NULL;
    ll *currNode=head;
    ll *nextNode;
    int count=0;
    while(currNode!=NULL&&count<k){
    
           nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
        count++;
     }
    if(nextNode!=NULL){
    head->next=reverseK(nextNode,k);//head reverse ho jayega to vo last ho jayega  aur isilye head->next(i.e last wli node) se next k node link ho jayegi
    }
return prevNode;
}

int main(){
    ll *head=NULL;
    int choice,value,k;
    do{
        printf("Enter:1-insertion,2-Reverse,3-Reverse by K order,3-Display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value to insert:");
            scanf("%d",&value);
            head=insertNode(head,value);
            break;
            case 2:reverse(head);
            break;
            case 3:printf("Enter the order:");
            scanf("%d",&k);
            head=reverseK(head,k);
            break;
            case 4:display(head);
            break;
            default:printf("Invalid Choice");
            exit(0);
        }
    }while(1);
    return 0;
}