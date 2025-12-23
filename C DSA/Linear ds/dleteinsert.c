#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};

// to create a node
struct node *createNode(int info)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory not available!!\n");
    }
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

// to traverse a linkedList
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->info);
        ptr = ptr->next;
    }
}
// case 1:insertion at Beggining
struct node *insertAtBeg(struct node *head, int info)
{
    struct node *newNode = createNode(info);
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        newNode->info = info;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        newNode->info = info;
    }
    return newNode;
}

// case 2:Insert in between
struct node *insertAtBetween(struct node *head, int info, int index)
{
    struct node *newNode = createNode(info);
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        newNode->info = info;
    }
    else
    {
        struct node *ptr = head;
        int i = 0;
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->info = info;
    }
    return head;
}

// case 3:insertion at last
struct node *insertAtLast(struct node *head, int info)
{
    struct node *newNode = createNode(info);
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        newNode->info = info;
    }
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->info = info;
    }
    return head;
}
// delete from Beggining
struct node *deleteBeg(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// delete from between
struct node *deleteBetween(struct node *head, int index)
{
    struct node *ptr = head;
    struct node *ptr1 = ptr->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
        i++;
    }
    ptr->next = ptr1->next;
    free(ptr1);
    return head;
}

// Delete at end
struct node *deleteLast(struct node *head)
{
    struct node *ptr = head;
    struct node *ptr1 = ptr->next;
    while (ptr1->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    ptr->next = NULL;
    free(ptr1);
    return head;
}

// delete after a node
//  struct node *deleteAfterNode(struct node *head,int index){
//  struct node *ptr=head;
//  struct node *ptr1=ptr->next;
//  while(ptr1->next!=index){
//      ptr=ptr->next;
//      ptr1=ptr1->next;
//  }
//  ptr->next=ptr1->next;
//  free(ptr1);
//  return head;
//  }

int main()
{
    struct node *head = NULL;
    int choice, data, index;
    while (1)
    { // so the condition is always true and loops repeats infinetly
        printf("\nEnter:");
        printf("\n1-Insertion At Beggining:");
        printf("\n2-Insertion At Between:");
        printf("\n3-Insertion At Last:");
        printf("\n4-Deletion At Beggining:");
        printf("\n5-Deletion At Between:");
        printf("\n6-Deletion At Last:");
        // printf("\n4-Deletion After node:");
        printf("\n7-traversal:");
        printf("\n8-Exit:");
        printf("\nEnter your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert at beggining:");
            scanf("%d", &data);
            head = insertAtBeg(head, data);
            break;
        case 2:
            printf("\nEnter the value to insert at between:");
            scanf("%d", &data);
            printf("\nEnter the index:");
            scanf("%d", &index);
            head = insertAtBetween(head, data, index);
            break;
        case 3:
            printf("\nEnter the value to insert at last:");
            scanf("%d", &data);
            head = insertAtLast(head, data);
            break;
        case 4:
            head = deleteBeg(head);
            break;
        case 5:
            printf("\nEnter the index:");
            scanf("%d", &index);
            head = deleteBetween(head, index);
            break;
        case 6:
            head = deleteLast(head);
            break;
        // case 4:printf("\nEnter the index :");
        //         scanf("%d",&index);
        // head=deleteAfterNode(head,index);
        case 7:
            traversal(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}
