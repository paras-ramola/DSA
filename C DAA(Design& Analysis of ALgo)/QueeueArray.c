#include<stdio.h>
#include<stdlib.h>
#define max 5


void push(int q[],int *front,int *rear,int item){
    if(*rear>=max-1){
        printf("\nQueue is Full!");
        return;
    }
    else if(*rear==-1){
        *front=*rear=0;
        q[*rear]=item;

    }
    else{
        *rear=*rear+1;
        q[*rear]=item; 
    }
}

void pop(int q[],int *front,int *rear){
    if(*front==-1){
        printf("\nQueue is empty");
    }
    else if(*front==*rear){
        printf("\nValue to de delted %d",q[*front]);
        *front=*rear=-1;
    }
    else{
         printf("\nValue to de delted %d",q[*front]);
        *front=*front+1;
    }
}

void traverse(int q[],int *front,int *rear){
    if(*front==-1){
        printf("\nQueue is Empty!");
        return ;
    }
    else{
        for(int i=*front;i<=*rear;i++){
            printf("\n%d",q[i]);
        }
    }
}


int  main(){
int choice,item;
int front=-1;
int rear=-1;
int q[max];

do{
    printf("\nEnter :1-Push,2-Pop,3-Traverse");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:printf("\nEnter the value to insert:");
        scanf("%d",&item);
        push(q,&front,&rear,item);
        break;

        case 2:pop(q,&front,&rear);
        break;
        case 3:traverse(q,&front,&rear);
        break;
    }
}
while(1);
return 0;



}