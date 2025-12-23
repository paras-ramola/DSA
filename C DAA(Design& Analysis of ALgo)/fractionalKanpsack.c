#include<stdio.h>


void knapsack(int num,float weight[],float profit[],int capacity){

//finding value density
    float ratio[num],temp;

    for(int i=0;i<num;i++){
        ratio[i]=profit[i]/weight[i];
    }

//swaping in order of decreasing value density
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(ratio[j]>ratio[i]){
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }

float frac[num],totalProf=0.0;
int i,u;
 u=capacity;

for(i=0;i<num;i++){
    frac[i]=0.0;
}

for(i=0;i<num;i++){
    if(weight[i]>u) break;
    else{
        frac[i]=1.0;
        u=u-weight[i];
        totalProf=totalProf+profit[i];
    }
}

if(i<num){
    frac[i]=(float)u/weight[i];
}
totalProf=totalProf+(frac[i]*profit[i]);

   printf("\nThe fraction of object is:- ");
   for (i = 0; i < num; i++)
      printf("%f\t", frac[i]);

   printf("\nMaximum profit is:- %f", totalProf);




}
int main(){
    int num;
    printf("Enter the number of objects:");
    scanf("%d",&num);
    float weight[num],profit[num];
    int capacity;


    for(int i=0;i<num;i++){
    printf("Enter weight and profit of object %d: ",i+1);
        scanf("%f",&weight[i]);
        scanf("%f",&profit[i]);
    }

    printf("Enter the capacity of Knapsack:");
    scanf("%d",&capacity);

    

    knapsack(num,weight,profit,capacity);
}