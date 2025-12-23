// //Simple Queue
// //1.Static Implementation of Simple Queue
// #include<stdio.h>
// #include<stdlib.h>
// #define max 10

// void insertq(int q[],int *front,int *rear,int val){
//     if(*rear==max-1){
//         printf("Queue is FULL!!\n");
//     }
//     else if(*rear==-1){//no element
//         *front=*rear=0;
//         q[*rear]=val;
//     }
//     else{
//         *rear=*rear+1;
//         q[*rear]=val;
//     }
// }

// void deleteq(int q[],int *front,int *rear){
//     if(*front>=0){
//         printf("Element to be Deleted is:%d\n",q[*front]);
//         *front=*front+1;
//     }
//     else if(*front==*rear){
//         *front=*rear=-1;
//     }
//     else{
//         printf("Queue is EMPTY!!\n");
//     }
// }

// void traverseq(int q[],int *front,int *rear){
//     int i;
//     if(*rear==-1){//or(*front==-1)
//         printf("Queue is EMPTY\n");
//     }
//     else{
//         for(i=*front;i<=*rear;i++){
//             printf("%d\t",q[i]);
//         }
//     }
// }

// int main(){
//     int choice,item;
//     int q[max];
//     int front=-1;
//     int rear=-1;
//     do{
//         printf("Enter 1-insertion,2-deletion &3-traverse:\n");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:printf("Enter Value to Insert:\n");
//                 scanf("%d",&item);
//             insertq(q,&front,&rear,item);
//             break;
//         case 2:
//             deleteq(q,&front,&rear);
//             break;
//         case 3:
//             traverseq(q,&front,&rear);
//             break;
//         default:
//             printf("Invalid syntax\n");
//             exit(0);
//         }
//     } while (1);
//     return 0;
// }

//2.Dynamic Implementation of Simple Queue
#include<stdio.h>
#include<stdlib.h>

 typedef struct queue{
    int info;
    struct queue *next;
}sq;

void insertq(sq **front,sq **rear,int val){
    sq *temp=(sq*)malloc(sizeof(sq));
    if(temp==NULL){
        printf("\nMemory FULL!!\n");
        return;
    }
else if(*rear==NULL){
    *front=*rear=temp;
    temp->next=NULL;
    temp->info=val;
}
else{
    (*rear)->next=temp;
    temp->next=NULL;
    *rear=temp;
    temp->info=val;
}
}

void deleteq(sq**front,sq** rear){
    if(*front==NULL){
        printf("\nQueue Underflow!!\n");
    }
    else{
        sq *p1=*front;
        printf("Element to be deleted:%d\n",p1->info);
        (*front)=(*front)->next;
        free(p1);
    }
}

void displayq(sq **front,sq **rear){
    sq *ptr=*front;
    if(*front=NULL){
        printf("\nEmpty Queue!!\n");
    }
    else{
        while(ptr){
            printf("\n%d\n",ptr->info);
            ptr=ptr->next;
        }
    }
}

int main(){
    int choice,item;
  sq *front=NULL;
  sq *rear=NULL;
    do{
        printf("Enter 1-insertion,2-deletion &3-traverse:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:printf("\nEnter Value to Insert:");
                scanf("%d",&item);
            insertq(&front,&rear,item);
            break;
        case 2:
            deleteq(&front,&rear);
            break;
        case 3:
            displayq(&front,&rear);
            break;
        default:
            printf("\nWrong Choice!!\n");
            exit(0);
        }
    } while (1);
    return 0;
}

