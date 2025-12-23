#include <stdio.h>
#define max 10

int top = -1;           
int stack[max];

int isFull() {
   if(top==max-1){
    return 1;
   }else{
    return 0;
   }
}

int isEmpty() {
    if(top==-1){
    return 1;
   }else{
    return 0;
   }
}

// Push an element onto the stack
void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        top++;
        stack[top] = num;
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is Empty...\n");
        return -1;
    } else {
        char c=stack[top];
        top--;
        return c;
    }
}


void printStack() {
    if (!isEmpty()) {
        int temp = pop();
        printStack();
        printf(" %d ", temp);
        push(temp);
    }
}

void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
    } else {
        int topElement = pop();
        insertAtBottom(item);
        push(topElement);
    }
}

void reverse() {
    if (!isEmpty()) {
        int topElement = pop();
        reverse();
        insertAtBottom(topElement);
    }
}

// Main function
int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Original Stack\n");
    printStack();
    reverse();
    printf("\nReversed Stack\n");
    printStack();
    return 0;
}
