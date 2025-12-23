#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node{
    int info;
    struct node* next;
}sn;

void traversal(struct node*ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->info);
        ptr=ptr->next;
    }
}

int main(){
sn* head;
sn* first;
sn* second;
sn* third;
sn* fourth;
head=(sn*)malloc(sizeof(sn));
first=(sn*)malloc(sizeof(sn));
second=(sn*)malloc(sizeof(sn));
third=(sn*)malloc(sizeof(sn));
fourth=(sn*)malloc(sizeof(sn));

head->info=4;
head->next=first;
first->info=11;
first->next=second;
second->info=8;
second->next=third;
third->info=9;
third->next=fourth;
fourth->info=7;
fourth->next=NULL;
traversal(head);


}