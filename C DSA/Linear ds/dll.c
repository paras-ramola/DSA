#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
}dll;
 dll *createNode(int info){
    dll *newNode=(dll *)malloc(sizeof(dll));
    if(newNode==NULL){
        printf("Memory Full\n");
    }
    else{
        newNode->info=info;
        newNode->next=NULL;
        newNode->prev=NULL;
    }
    return newNode;
 };
void display(dll *ptr){
while(ptr!=NULL){
    printf("Element:%d\n",ptr->info);
    ptr=ptr->next;
}
}
dll *insertAtBeg(dll *head,int info){
    dll *newNode=createNode(info);
    if(head==NULL){
        newNode->info=info;
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
    }
    else{
        dll *ptr=head;
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        newNode->prev=NULL;
        newNode->info=info;
    }
    return head;
};
dll *insertAtLast(dll *head,int info){
    dll *newNode=createNode(info);
    if(head==NULL){
        newNode->info=info;
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
    }
    else{
        dll *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        newNode->next=NULL;
       ptr->next=newNode;
       newNode->prev=ptr;
        newNode->info=info;
    }
    return head;
};
dll *deleteAtBeg(dll *head){
if(head==NULL){
    printf("Empty List\n");
}
else{
dll *ptr=head;
if(head->next==NULL){
free(ptr);
head=NULL;
}
else{
head=head->next;
free(ptr);
head->prev=NULL;
return head;
}
}};
dll *deleteAtLast(dll *head){
if(head==NULL){
    printf("Empty List\n");
}
else{
dll *ptr=head;
dll *ptr1=ptr->next;
if(head->next==NULL){
free(ptr);
head=NULL;
}
else{
while(ptr1->next!=NULL){
    ptr1=ptr1->next;
    ptr=ptr->next;
}
ptr->next=NULL;
free(ptr1);
return head;
}
}};

int main(){
    dll *head= NULL;
    int choice ,info;
    do{
        printf("Enter: \n");
        printf("1-Insertion at Beggining \n");
        printf("2-Insertion at Last \n");
        printf("3-Deletion at Beggining \n");
        printf("4-Deletion at Last \n");
        printf("5-Display\n");
        printf("6-Count Number of Nodes\n:");
        printf("7-exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nEnter the data to insert at begginong:");
            scanf("%d",&info);
            head=insertAtBeg(head,info);
            break;
            case 2:
            printf("\nEnter the data to insert at last:");
            scanf("%d",&info);
            head=insertAtLast(head,info);
            break;
            case 3:
            head=deleteAtBeg(head);
            break;
            case 4:
            head=deleteAtLast(head);
            break;
            case 5:display(head);
            break;
            // case 6:printf("NUmber of node in the Linked list are :%d\n",countNodes(head));
            // break;
            case 7:exit(0);
            default:printf("Invalid Choice\n");
        }
    }while(1);
}