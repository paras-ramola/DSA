// Circular Queue using Array

#include <stdio.h>
#include <stdlib.h>
#define max 5

void insertCQ(int q[], int *front, int *rear, int val)
{
    if (*front == (*rear + 1) % max)
    {
        printf("Queue is FULL!!\n");
    }
    else if (*rear == -1)
    {
        *front = *rear = 0;
        q[*rear] = val;
    }
    else
    {
        *rear = (*rear + 1) % max; // circular increment
        q[*rear] = val;
    }
}

void deleteCQ(int q[], int *front, int *rear)
{
    if (*front >= 0)
    {
        printf("\nElement to be deleted is:%d", q[*front]);
        *front = (*front + 1) % max; // value of front increased
    }
}
void displayCQ(int q[], int *front, int *rear)
{
    int i;
    if (*front == -1)
    { // or(*rear==-1)
        printf("\nQueue is Empty");
    }
    else
    {
        for (i = *front; i != *rear; i = (i + 1) % max)
        {
            printf("%d\n", q[i]);
        }
    }
    printf("%d", q[i]);
}
int main()
{
    int q[max];
    int choice, item;
    int front = -1;
    int rear = -1;
    do
    {
        printf("\nEnter your choice:1 for insertion,2 for Deletion,3 for Traversal");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert:");
            scanf("%d", &item);
            insertCQ(q, &front, &rear, item);
            break;
        case 2:
            deleteCQ(q, &front, &rear);
            break;
        case 3:
            displayCQ(q, &front, &rear);
            break;
        default:
            printf("Wrong Choice!!\n");
            exit(0);
        }
    } while (1);
    return 0;
}
