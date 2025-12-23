#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100

int top = -1;
char stack[Max];
char infix[Max], postfix[Max];

void inToPost();
int precedence(char);
void printExp();
int space(char);
void push(char);
char pop();
int isEmpty();
int isFull();

int main()
{
    printf("Enter the Infix Expression:\n");
    gets(infix); // gets is unsafe-buffer overflow
    // fgets(infix,Max,stdin);
    inToPost();
    printExp();
}

void inToPost()
{
    int i = 0, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        { // if symbol is not a blank space
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default: // if symbol is operand
                postfix[j++] = symbol;
            }
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

void printExp()
{
    int i = 0;
    printf("The Equivalent Postfix Expression is:");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int space(char c)
{ // is symbol is a blank space or Tab
    if (c == ' ' || c == '\t')
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if (top == Max - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char c)
{
    if (isFull())
    {
        printf("\nStack OverFlow!\n");
        exit(1); // terminates the whole program
    }
    top++;
    stack[top] = c;
}

char pop()
{
    char c;
    if (isEmpty())
    {
        printf("\nStack Underflow!");
        exit(1);
    }
    else
        c = stack[top];
    top--;
    return c; // returns the deleted value
}
