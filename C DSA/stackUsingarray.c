#include<stdio.h>
#include<stdlib.h>
#define max 10

void push(int stk[],int *Top,int val){
    if(*Top<max){
        *Top=*Top+1;
        stk[*Top]=val;
    }
    else{
        printf("Stack is Full!!\n");
    }
}
void pop(int stk[],int *Top,int *val){
    if(*Top>=0){
        printf("The value to be deleted is %d\n",stk[*Top]);
    *Top=*Top-1;
    }
    else{
        printf("Stack is Empty!!\n");
        exit(0);
    }
}

void Traverse(int stk[],int *Top){
    int temp=*Top;//humne temp isliye liya kyunki while traversing the stack *top ki value -1 ho jayegi aur vo exit ho jyegi and if not exit ,to after displaying value delte bhi ni ho payegi 
    while(temp>=0){
        printf("%d\n",stk[temp]);
        temp=temp-1;
    }
    if(temp==-1){
        exit(0);
    }
}
int main(){
    int choice,item;
    int stk[max];
    int Top=-1;
    do{
    printf("Enter 1-insertion,2-deletion &3-traverse:\n");
    scanf("%d",&choice);

        switch (choice)
        {
            case 1: printf("Enter the value you want to push:\n");
                   scanf("%d",&item);
            push(stk,&Top,item);
            break;
            case 2:pop(stk,&Top,&item);
            break;
            case 3:Traverse(stk,&Top);
            break;
            default:printf("Invalid syntax!!");
            exit(0);
}
}while(1);
}