#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct sNodetype
{
    int info;
    struct sNodetype* next;
}sn;
int main(){
struct sNodetype* head;
head=NULL;
struct sNodetype* Temp;
Temp=(struct sNodetype*)malloc(sizeof(struct sNodetype));
if(Temp==NULL){
    printf("No Space Available");
}
else{
    printf("Enter The Value");
    scanf("%d",&(Temp->info));
    printf("The node value is %d",Temp->info);
    Temp->next=NULL;
}
}

