#include<stdio.h>


void printArray(int *A,int n){
      for(int i=0;i<n;i++){
        printf("\n");
        printf("%d",A[i]);
    }

}

void selectionSort(int *A,int n){
    int indexOfMin,j,temp;
    for(int i=0;i<=n-1;i++){
        indexOfMin=i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[indexOfMin]){
                indexOfMin=j;
            }
        }
        temp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=temp;
    }
}


int main(){
    //00 01 02 03 04
    //03,05,02,13,12
    int n;
    printf("Enter the size of an array");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printArray(A,n);
    selectionSort(A,n);
    printf("\nAfter Sorting:");
    printArray(A,n);
}