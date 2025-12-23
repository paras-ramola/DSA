#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

void push(struct node **front,struct node **rear,int item){
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
    printf("\nMemory Full");
    }
    else if(*rear==NULL){
        *front=*rear=temp;
        temp->next=NULL;
        temp->info=item;
    }
        else{
            (*rear)->next=temp;
            temp->next=NULL;
            temp->info=item;
            *rear=temp;
        }
    }


void pop(struct node **front,struct node **rear){
if(*front==NULL){
    printf("Underflow");
}else{
    struct node *temp=*front;
    (*front)=(*front)->next;
     if (*front == NULL) {
            *rear = NULL;
        }
    free(temp);
}

}

void traverse(struct node **front,struct node **rear){
    struct node *ptr=*front;
    if(*front==NULL){
        printf("\nEmpty Queue!!\n");
    }
    else{
        while(ptr){
            printf("\n%d\n",ptr->info);
            ptr=ptr->next;
        }
    }
}


int  main(){
int choice,item;
struct node *front=NULL;
struct node *rear=NULL;

do{
    printf("\nEnter :1-Push,2-Pop,3-Traverse");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:printf("\nEnter the value to insert:");
        scanf("%d",&item);
        push(&front,&rear,item);
        break;

        case 2:pop(&front,&rear);
        break;
        case 3:traverse(&front,&rear);
        break;
    }
}
while(1);
return 0;
}