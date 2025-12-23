#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
    int info;
    struct node* next;
}cll;

cll *createNode(int info){
    cll *newNode=(cll*)malloc(sizeof(cll));
    newNode->info=info;
    newNode->next=NULL;
    return newNode;
}

void display(cll *head){
    cll *ptr=head;
    if(ptr==NULL){
        printf("Empty List!!\n");
    }
    do{
        printf("Element:%d\n",ptr->info);
        ptr=ptr->next;//now ptr=head->next
    }while(ptr!=head);
}

cll *insertAtBeg(cll *head,int info){
cll *newNode=createNode(info);
if(head==NULL){
    newNode->info=info;
    newNode->next=newNode;
    head=newNode;
}
else{
    cll *ptr=head->next;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
    head=newNode;
    newNode->info=info;
}
return head;
}

cll *insertAtLast(cll *head,int info){
    cll *newNode=createNode(info);
    if(head==NULL){
        newNode->info=info;
    newNode->next=newNode;
    head=newNode;
    }
    else{
        cll *ptr=head->next;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        newNode->next=head;
        ptr->next=newNode;
        newNode->info=info;
    }
    return head;
}

cll *deleteAtBeg(cll *head){
    if(head==NULL){
        printf("Empty List!!\n");
    }
    else{
        cll *ptr=head->next;
        cll *ptr1=head;
        if(ptr==head){
            free(ptr);
            head=NULL;
        }
            else{        
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=head->next;
        free(ptr1);
        head=ptr->next;
    }
    return head;
}
}

cll* deleteAtLast(cll *head){
     if(head==NULL){
        printf("Empty List!!\n");
    }
    else{
        cll *ptr=head->next;
        cll *ptr1=head;
        if(ptr==head){
            free(ptr);
            head=NULL;
        }
        else{
            while(ptr->next!=head){
                ptr=ptr->next;
                ptr1=ptr1->next;
            }
            ptr1->next=head;
            free(ptr);
        }
            return head;
}
}

int countNodes(cll *head){
    int count =0;
    if(head==NULL)
        return 0;
    else{
        cll *ptr=head;
        do{
            count++;
            ptr=ptr->next;
        }while(ptr!=head);
        return count;
    }
}

int main(){
    cll *head= NULL;
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
            case 6:printf("NUmber of node in the Linked list are :%d\n",countNodes(head));
            break;
            case 7:exit(0);
            default:printf("Invalid Choice\n");
        }
    }while(1);
}