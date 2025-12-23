#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *push(struct node *top,int item){
    struct node *temp;
    temp=(struct node *) malloc(sizeof(struct node));
    if(temp==NULL) printf("\nMemory Full");
    else{
        temp->next=top;
        top=temp;
        temp->info=item;

    }
    return top;
}

struct node *pop(struct node *top){
    if(top==NULL) printf("\nMemory Full");
    else{
    struct node *temp=top;
    printf("\nPoped item: %d",temp->info);
    top=top->next;
    free(temp);
    }
    return top;

}

struct node*traversal(struct node *top)
{
    if(top==NULL){
        printf("\nList is Empty");
    }
    else{
        struct node *temp=top;
        while(temp!=NULL){
            printf("\n%d",temp->info);
            temp=temp->next;
        }
    }
    return top;
};



int main(){
    struct node*top=NULL;
    int choice,item;

    do{
    printf("\nEnter");
    printf("\n1-Push");
    printf("\n2-Pop");
    printf("\n3-Delete");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:printf("Enter the item to insert");
    scanf("%d",&item);
        top=push(top,item);
        break;
    case 2:top=pop(top);
        break;
    case 3:traversal(top);
        break;
    
    default:printf("Wrong Choice");
    exit(0);
        break;
    }
}
while(1);
return 0;
}