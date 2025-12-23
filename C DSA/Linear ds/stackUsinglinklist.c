#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int info;
    struct stack *next;
} st;

st *push(st *top, int item)
{
    st *temp;
    temp = (st *)malloc(sizeof(st));
    if (temp == NULL)
    {
        printf("Memory is FULL!!");
    }
    else
    {
        temp->next = top;
        top = temp;
        temp->info = item;
    }
    return top;
}

st *pop(st *top)
{
    if (top == NULL)
    {
        printf("Linked List is Empty!!\n");
    }
    else
    {
        st *p1 = top;
        printf("Element to be deleted: %d\n", top->info);
        top = top->next;
        free(p1);
    }
    return top;
}
st *traverse(st *top)
{
    if (top == NULL)
    {
        printf("Stack is Empty!!\n");
    }
    else
    {
        st *p1;
        p1 = top;
        while (p1 != NULL)
        {
            printf("%d\n", p1->info);
            p1 = p1->next;
        }
    }
    return top;
}

int main()
{
    st *top = NULL;
    int choice, value;

    do
    {
        printf("Enter 1-insertion,2-deletion &3-traverse:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value you want to push:\n");
            scanf("%d", &value);
            top = push(top, value);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            top = traverse(top);
            break;
        default:
            printf("Invalid syntax!!");
            exit(0);
        }
    } while (1);
}
