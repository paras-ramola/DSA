#include<stdio.h>
#include<stdlib.h>
#define max 5
int A[max];
int Top=-1;
void push(){
    int value;
    printf("Enter the value to insert:");
    scanf("%d",&value);
    if(Top==max-1){
        printf("Stack is Full\n");
        return;
    }
    else{
        Top++;
        A[Top]=value;
    }

}

void pop(){
    int value;
    if(Top==-1){
        printf("Stack is Empty!");
        return;
    }
    else{
        value=A[Top];
        printf("Value to be delted %d\n",value);
        Top--;
    }
}
void traverse(){
    int T;
    if(Top==-1){
        printf("Stack is empty!");
        return;
    }
    else{
        T=Top;
        while(T>=0){
            printf("%d\n",A[T]);
            T--;
        }
    }
}


int main(){

    do{
        int choice;
        printf("Enter: ");
        printf("1-Push");
        printf("2-Pop");
        printf("3-Traverse");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:traverse();
            break;
            default:printf("Wrong Choice");
            exit(0);
        }

    }while(1);
    return 0;
}
