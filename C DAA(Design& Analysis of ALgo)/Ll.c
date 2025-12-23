#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node* createNode(int info){
    struct node *newNode=(struct node *) malloc(sizeof(struct node));
    if(newNode==NULL) printf("Memory Not Available!");

    newNode->info=info;
    newNode->next=NULL;
    return newNode;
}

void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("\n%d",ptr->info);
        ptr=ptr->next;
    }
}

struct node *insertAtBeg(struct node *head,int info){
    struct node *newNode=createNode(info);
    newNode->next=head;
    head=newNode;
    return head;
}

struct node *insertAtBtwn(struct node *head,int info,int index){
    struct node *newNode=createNode(info);

    if(head==NULL){
        newNode->next=head;
        head=newNode;
        return head;
    }
    else{
    struct node *ptr=head;
    int i=0;
    
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
    return head;
    }

}
struct node *insertAtLast(struct node *head,int info){
    struct node *newNode=createNode(info);

    if(head==NULL){
        newNode->next=head;
        head=newNode;
        return head;
    }
    else{
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    newNode->next=NULL;
    ptr->next=newNode;
    return head;
    }

}

int main(){
    struct node *head=NULL;
    int choice ,item,index;
    do{
        printf("\nEnter:");
        printf("\n1-Insert at Beggining:");
        printf("\n2-Insert at Between:");
        printf("\n3-Insert at end:");
        printf("\n4-Traverse:");

        scanf("%d",&choice);

        switch(choice){
            case 1:printf("\nEnter the item to insert:");
            scanf("%d",&item);
            head=insertAtBeg(head,item);
            break;
            case 2:printf("\nEnter the item to insert At Between:");
            scanf("%d",&item);
            printf("\nEnter the index to insert:");
            scanf("%d",&index);
            head=insertAtBtwn(head,item,index);
            break;
            case 3:printf("\nEnter the item to insert at Last:");
            scanf("%d",&item);
            head=insertAtLast(head,item);
            break;

            case 4:traversal(head);
            break;

            default:printf("Wrong Choice");
            exit(0);
        }



    }
    while(1);
    return 0;
}