#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define Max 100

int top=-1;
char stack[Max];//Stack jisme value push ya pop hogi
void push(char);
char pop();
int isEmpty();
int isFull();
int checkExp(char *);//?
int match_Exp(char a,char b);

int main(){
    int balanced;
    char exp[Max];
    printf("Enter the algebraic expression:");
    gets(exp);//Reads characters from user & stores them as a C string into exp until a newline character or the end-of-file is reached.
    balanced=checkExp(exp);
}

int checkExp(char *s){
    int i=0;
    char temp;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='['||s[i]=='{'||s[i]=='('){
            push(s[i]);
        }
        if(s[i]==']'||s[i]=='}'||s[i]==')'){
            if(isEmpty()){
                printf("\nRigth Brackets are more than left!! ");
                return 0;
            }
            else{
                temp=pop();
                if(!match_Exp(temp,s[i])){
                    printf("\nBrackets are mismathced!!");
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        printf("\nBrackets are Well Balanced\n");
        return 1;
    }
    else{
        printf("\nLeft Brackets are more than Rigth Brackets!!");
        return 0;
    }
}
int match_Exp(char a,char b){
    if(a=='['&&b==']')
        return 1;
    if(a=='('&&b==')')
        return 1;
    if(a=='{'&&b=='}')
        return 1;
    else
    return 0;
}
//
int isFull(){
    if(top==Max-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(char c){
    if(isFull()){
        printf("\nStack OverFlow!\n");
        exit(1);//terminates the whole program
    }
    top++;
    stack[top]=c;
}

char pop(){
    char c;
    if(isEmpty()){
        printf("\nStack Underflow!");
        exit(1);
    }
    else
    c=stack[top];
    top--;
    return c;//returns the deleted value
}
