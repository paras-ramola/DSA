#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is:%d\n", ptr->info);
        ptr = ptr->next;
    }
};

struct node *createNode(int info)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory not Available!!\n");
    }
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
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
    ptr->next = ptr1->next;
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
        printf("\n1-Deletion At Beggining:");
        printf("\n2-Deletion At Between:");
        printf("\n3-Deletion At Last:");
        // printf("\n4-Deletion After node:");
        printf("\n5-traversal:");
        printf("\n6-Exit:");
        printf("\nEnter your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = deleteBeg(head);
            break;
        case 2:
            printf("\nEnter the index:");
            scanf("%d", &index);
            head = deleteBetween(head, index);
            break;
        case 3:
            head = deleteLast(head);
            break;
        // case 4:printf("\nEnter the index :");
        //         scanf("%d",&index);
        // head=deleteAfterNode(head,index);
        case 5:
            traversal(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}

// // Case 1:Deleting ht first element from the linked list
// struct node *deleteFirst(struct node  *head){
//     struct node* ptr=head;
//     head=head->next;
//     free(ptr);
//     return head;
// }

// // Case 2:Deleting the element at a given index from linked list
// struct node* deleteAtIndex(struct node* head,int index)
// {
//     struct node* p=head;
//     struct node* q=head->next;
//     for(int i=0;i<=index-1;i++){
//         p=p->next;
//         q=q->next;
//     }
//     p->next=q->next;
//     free(q);
//     return head;//Why?//taki to vo traverse func m jake starting se print kare
// }

// // Case 3:Deleting the Last Element
// struct node* deleteAtLast(struct node* head)
// {
//     struct node* p=head;
//     struct node* q=head->next;
//   while(q->next!=NULL){
//         p=p->next;
//         q=q->next;
//     }
//     p->next=NULL;
//     free(q);
//     return head;//Why?
// }

// // Case 4:Deleting the element with given Valuefrom linked list
// struct node* deleteAtValue(struct node* head,int value)
// {
//     struct node* p=head;
//     struct node* q=head->next;
//     while(q->info!=value && q->next!=NULL){
//         p=p->next;
//         q=q->next;
//     }
//     if(q->info==value){
//     p->next=q->next;
//     free(q);
//     }
//     else{
//         printf("Value Not Found at Node!");
//     }
//     return head;//Why?
// }

// int main(){
// struct node *head;
// struct node* second;
// struct node* third;
// struct node* fourth;

// head=(struct node*)malloc (sizeof(struct node));
// second=(struct node*)malloc (sizeof(struct node));
// third=(struct node*)malloc (sizeof(struct node));
// fourth=(struct node*)malloc (sizeof(struct node));

// head->info=4;
// head->next=second;
// second->info=3;
// second->next=third;
// third->info=8;
// third->next=fourth;
// fourth->info=1;
// fourth->next=NULL;

// printf("Linked List before Deletion\n");
// traversal(head);
// // head= deleteFirst(head);
// // head=deleteAtIndex(head,2);
// // head=deleteAtLast(head);
// head=deleteAtValue(head,0);
// printf("Linkred List after Deletion\n");
// traversal(head);

//     return 0;
// }