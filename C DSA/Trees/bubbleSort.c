#include<stdio.h>

void printArray(int *A,int n){
      for(int i=0;i<n;i++){
        printf("\n%d\n",A[i]);
    }

}

void bubbleSort(int *A,int n){
    int temp;
    for(int i=0;i<n-1;i++){//number of passes
        for (int j=0;j<n-1-i;j++){//number of comparisions in each pass
           if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    printf("sorted array:");
}


int main(){
    int n;
    printf("Enter the size of an array");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printArray(A,n);//printing the array before sorting
    bubbleSort(A,n);//Function to bubble sort the array
    printf("Array after Sorting:");//printing the array before sorting
    printArray(A,n);
    return 0;
}



// to make bubble sort adaptive
// void bubbleSort(int *A,int n){
//     int temp;
//     int isSorted=0;
//     for(int i=0;i<n-1;i++){//number of passes
//         printf("Working on %d pass\n",i+1);
//         isSorted=1;//arr is already sorted
//         for (int j=0;j<n-1-i;j++){//number of comparisions in each pass
//            if(A[j]>A[j+1]){
//                 temp=A[j];
//                 A[j]=A[j+1];
//                 A[j+1]=temp;
//                 isSorted=0;//arr is not sortedkyunki use is loop k andr aana pda
//             }
//         } 
//         if(isSorted){
//             return;//return after 1 pass
//     }
//     }
// }