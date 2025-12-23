#include<stdio.h>

void printArray(int *A,int n){
      for(int i=0;i<n;i++){
        printf("\n");
        printf("%d",A[i]);
    }

}
void insertionSort(int *A,int n){
    int key,j;
    for(int i=1;i<=n-1;i++){//for each pass
        key=A[i];
        j=i-1;//index of prev element
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;//j=-1
    }

}

int main(){
    int n;
    printf("Enter the size of an array");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printArray(A,n);
    insertionSort(A,n);
    printf("\nAfter Sorting:");
    printArray(A,n);
}