#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort activities by their finish times
void sortActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {//ascending order
                swap(&finish[i], &finish[j]);//both are connnected
                swap(&start[i], &start[j]);
            }
        }
    }
}

int printMaxActivities(int start[],int finish[],int n){

//sort finish array
sortActivities(start,finish,n);

 // Select the first activity
  printf("Activity no: %d\n", 0);

    int i=0;
    int count=1;

    for(int j=1;j<n;j++){
        if(start[j]>=finish[i]){
          printf("Activity no: %d\n",j);
         i=j;
         count++;
     }
    }
    return count;
}



int main(){
    int start[]={1,7,3,4,2,8,9,9,12,11 };
    int finish[]={3,10,4,7,5,9,11,13,14,12 };
    int n=sizeof(start)/sizeof(start[0]);

   int num= printMaxActivities(start,finish,n);
   printf("\ncount:%d",num);
    return 0;
}