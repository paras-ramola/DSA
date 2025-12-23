#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Jobs{
    char id;
    int deadline;
    int profit;
}Jobs;


int compare(const void *a,const void *b){
    Jobs* temp1=(Jobs*)a;
    Jobs* temp2=(Jobs*)b;
    return (temp2->profit-temp1->profit);//if +ve,->temp2 is greatert than temp1
}

int min(int num1,int num2){
    if(num1<num2) return num1;
    else return num2;
}
int main(){
   Jobs arr[] = { 
      { 'a', 2, 100 },
      { 'b', 2, 20 },
      { 'c', 1, 40 },
      { 'd', 3, 35 },
      { 'e', 1, 25 }
   };//making a array of struct Jobs

   int n=sizeof(arr)/sizeof(arr[0]);
   printf("Maximum profit Sequence of Jobs:\n");
   qsort(arr,n,sizeof(Jobs),compare);

   int result[n];
   bool slots[n];

   for(int i=0;i<n;i++){
    slots[i]=false;
   }
   for(int i=0;i<n;i++){
    for(int j=min(n,arr[i].deadline)-1;j>=0;j--){

        if(slots[j]==false){
            result[j]=i;
            slots[j]=true;
            break;
        }
    }
   }
   for(int i=0;i<n;i++){
    if(slots[i]){
        printf("%c",arr[result[i]].id);
    }
   }
       return 0;

}