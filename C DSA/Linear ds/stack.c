//Implementation of Stack

//1.
#include <stdio.h>
#include <stdlib.h>
#define max 5
void push();
void pop();
void traverse();
int A[max];
int Top = -1;

void push()
{
    int value;

    if (Top == max - 1)
    {
        printf("Stack is FULL!!\n");
        return;
    }
    else
    {
        printf("Enter the value you want to push:\n");
        scanf("%d", &value);
        Top = Top + 1;
        A[Top] = value;
    }
}

void pop()
{
    if (Top == -1)
    {
        printf("Stack is EMPTY!!\n");
        return;
    }
    else
    {
        printf("The value to be deleted is %d\n", A[Top]);
        Top = Top - 1;
    }
}

void traverse()
{
    int T;
    if (Top == -1)
    {
        printf("Stack is EMPTY!!\n");
    }
    else
    {
        printf("The elements are:\n");
        T = Top;
        while (T >= 0)
        {
            printf("%d\t", A[T]);
            T--;
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("Enter 1-insertion,2-deletion &3-traverse:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        default:
            printf("Invalid syntax\n");
            exit(0);
        }
    } while (1);
    return 0;
}

//2.Static Implementation of Stack-(using Array)

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
    int temp=*Top;
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

//3.Dynamic Implementation of Stack
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct stack{
    int info;
    struct stack *next;
}st;

st* push(st* top,int item){
st* temp;
temp=(st*)malloc(sizeof(st));
if(temp==NULL){
    printf("Memory is FULL!!");
}
else{
    temp->next=top;
    top=temp;
    temp->info=item;
}
return top;
}

st* pop(st* top){
if(top==NULL){
    printf("Linked List is Empty!!\n");
}
else{
    st* p1;
    p1=top;
    printf("Element to be deleted: %d\n",top->info);
    top=top->next;
    free(p1);
}
return top;
}
st* traverse(st* top){
    if(top==NULL){
        printf("Stack is Empty!!\n");
    }
    else{
        st* p1;
        p1=top;
        while( p1!=NULL){
            printf("%d\n",p1->info);
            p1=p1->next;
        }
    }
    return top;
}

int main(){
    st *top=NULL;
    int choice,value;

       do{
    printf("Enter 1-insertion,2-deletion &3-traverse:\n");
    scanf("%d",&choice);

        switch (choice)
        {
            case 1: printf("Enter the value you want to push:\n");
                   scanf("%d",&value);
           top= push(top,value);
            break;
            case 2:top=pop(top);
            break;
            case 3:top=traverse(top);
            break;
            default:printf("Invalid syntax!!");
            exit(0);
}
}while(1);
}
