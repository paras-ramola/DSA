#include <stdio.h>
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
void linkedlistTraversal(struct node *ptr)
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

int main()
{
    struct node *head = NULL; // struct:to return a value
    int choice, data, index;
    while (1)
    { // so the condition is always true and loops repeats infinetly
        printf("\nEnter:");
        printf("\n1-Insertion At Beggining:");
        printf("\n2-Insertion At Between:");
        printf("\n3-Insertion At Last:");
        printf("\n4-Traversal:");
        printf("\n5-Exit:");
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
            linkedlistTraversal(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}

// GIVING INPUT MANUALLY
//  for traverse
//  void linkedlistTraversal(struct node *ptr)
//  {
//      while (ptr != NULL)
//      {
//          printf("Element:%d\n", ptr->info);
//          ptr = ptr->next;
//      }
//  }

// // Case:1
// struct node *insertAtFirst(struct node *head, int info)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));
//     ptr->next = head;
//     ptr->info = info;
//     return ptr;//is time ptr hi head h to ptr return kra
// }
// // Case:2
// struct node *insertAtIndex(struct node *head, int info, int index)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));
//     struct node *p = head; // is p node ke baad ptr node ko insert krna h
//     int i = 0;
//     while (i != index - 1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->info = info;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// // Case:3
// struct node *insertAtEnd(struct node *head, int info)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));
//     struct node *p = head;
//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
//     ptr->info = info;
//     ptr->next = NULL;
//     p->next = ptr;
//     return head;
// }
// // case :4
// struct node *inserAfterNode(struct node *head, struct node *prevnode, int info)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));
//     ptr->info = info;
//     ptr->next = prevnode->next;
//     prevnode->next = ptr;
//     return head;
// }

// int main()
// {
//     struct node *head;
//     struct node *first;
//     struct node *second;
//     struct node *third;
//     struct node *fourth;
//     // Allocate Memory for nodes in the linked list in heap
//     head = (struct node *)malloc(sizeof(struct node));
//     first = (struct node *)malloc(sizeof(struct node));
//     second = (struct node *)malloc(sizeof(struct node));
//     third = (struct node *)malloc(sizeof(struct node));
//     fourth = (struct node *)malloc(sizeof(struct node));

//     // link first and second nodes

//     head->info = 4;
//     head->next = second;

//     // link second and third node
//     second->info = 89;
//     second->next = third;

//     // link third and fourth nodes
//     third->info = 90;
//     third->next = fourth;

//     // Terminate the list at fourth node
//     fourth->info = 98;
//     fourth->next = NULL;

//     printf("Linked List before Insertion:\n");
//     linkedlistTraversal(head);
//     head=insertAtFirst(head,9);
//    // head=insertAtIndex(head,56,2);
//     // head= insertAtEnd( head,57);
//    // head = inserAfterNode(head, second, 30);
//     printf("Linked List After Insertion:\n");
//     linkedlistTraversal(head);

//     return 0;
// }
