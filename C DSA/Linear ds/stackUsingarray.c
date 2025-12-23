#include<stdio.h>
#include<stdlib.h>
#define max 5

void push(int stk[],int *Top,int val){
    if(*Top<max){
        *Top=*Top+1;
        stk[*Top]=val;
    }
    else{
        printf("Stack is Full!!\n");
    }
}
void pop(int stk[],int *Top){
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
    int temp=*Top;
    while(temp>=0){
        printf("%d\n",stk[temp]);
        temp=temp-1;
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
            case 2:pop(stk,&Top);
            break;
            case 3:Traverse(stk,&Top);
            break;
            default:printf("Invalid syntax!!");
            exit(0);
}
}while(1);
}