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

struct node *deleteAtFrst(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
    

}
struct node *deleteAtBet(struct node *head,int index){
    struct node *ptr1=head;
    struct node *ptr2=ptr1->next;
   int i=0;
   while(i!=index-1){
    ptr1=ptr1->next;
    ptr2=ptr2->next;
    i++;
   }
   ptr1->next=ptr2->next;
   free(ptr2);
   return head;

    

}
struct node *deleteAtLast(struct node *head){
    if(head==NULL){
        printf("Empty list");
        exit(0);
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *ptr1=head;
    struct node *ptr2=ptr1->next;

   while(ptr2->next!=NULL){
    ptr1=ptr1->next;
    ptr2=ptr2->next;
   }
   ptr1->next=NULL;
   free(ptr2);
   return head; 
}

struct node *deleteAtGivenValue(struct node *head,int value){
    struct node *ptr1=head;
    struct node *ptr2=ptr1->next;
if(ptr1->info==value){
    head=head->next;
    free(ptr1);
    return head;
}
   while(ptr2->info!=value && ptr2->next!=NULL){
    ptr1=ptr1->next;
    ptr2=ptr2->next;
   }
   if(ptr2->info==value){
   ptr1->next=ptr2->next;
   free(ptr2);

}return head;

}


int main(){
    struct node *head=NULL;
    int choice ,item,index;
    int val;//Case 5
    do{
        printf("\nEnter:");
        printf("\n1-Insert");
        printf("\n2-Delete at Beggining:");
        printf("\n3-Delete at Between:");
        printf("\n4-Deelte at end:");
        printf("\n5-Deelte at a given value:");
        printf("\n6-Traverse:");

        scanf("%d",&choice);

        switch(choice){

            case 1:printf("\nEnter the item to insert :");
            scanf("%d",&item);
            head=insertAtLast(head,item);
            break;
            
            case 2:head=deleteAtFrst(head);
            break;
            case 3:printf("\nEnter the index to delete:");
              scanf("%d",&index);
            head=deleteAtBet(head,index);
            break;
            case 4:head=deleteAtLast(head);
            break;
            case 5:

            printf("\nEnter the value to delete:");
            scanf("%d",&val);
            head=deleteAtGivenValue(head,val);
            break;
            case 6:traversal(head);
            break;

            default:printf("Wrong Choice");
            exit(0);
        }



    }
    while(1);
    return 0;
}