// #include<stdio.h>

// int max(int a,int b){
//     if(a>=b) return a;
//     else return b;
// }
// int main(){
//     int n;
//     printf("Enter the number of object: ");
//     scanf("%d",&n);
//     int wt[n],val[n];
//     for(int i=0;i<n;i++){
//         printf("Enter val and weigth of object no:%d ",i);
//         scanf("%d",&val[i]);
//         scanf("%d",&wt[i]);
//     }

//     int W;//capacity of knapsack
//     printf("Enter the capcity of knapsack: ");
//     scanf("%d",&W);

//     int k[n+1][W+1];

//     for(int i=0;i<=n;i++){
//         for(int w=0;w<=W;w++){
//             if(i==0||w==0){
//                  k[i][w]=0;
//             }
//             else if(wt[i-1]<=w){
//                 k[i][w]=max(k[i-1][w],k[i-1][w-wt[i-1]]+val[i-1]);
//                 //value takea as wt[i-1] and val[i-1] instead of i because indexing for val and wt starts from zer
//             }

//             else{
//                 k[i][w]=k[i-1][w];
//             }
//         }
//     }

//     printf("Matrix: \n");
//     for(int i=0;i<=n;i++){
//         for(int w=0;w<=W;w++){
//             printf("%d\t",k[i][w]);
//         }
//         printf("\n");
//     }
//     printf("The maximum profit is : %d\n",k[n][W]);

// int maxi=k[n][W];//Total maximum profit

// int x=W;
//  printf("Items included in the knapsack:\n");

//  for(int i=n;i>0&& maxi>0;i--){

//     if(maxi==k[i-1][x]){//equals to previous value in a row
//         continue;//dont include item
//     }
//     else{
//         printf("Item %d (Value :%d , Weigth:%d)\n",i,val[i-1],wt[i-1]);

//         maxi=maxi-val[i-1];
//         x=x-wt[i-1];
//     }
//  }
// }



#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int V[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                V[i][w] = 0;
            else if (weights[i - 1] <= w)
                V[i][w] = max(values[i - 1] + V[i - 1][w - weights[i - 1]], V[i - 1][w]);
            else
                V[i][w] = V[i - 1][w];
        }
    }

    // Return the maximum value that can be put in a knapsack of capacity W
    return V[n][W];
}

int main() {
   int n;
    printf("Enter the number of object: ");
    scanf("%d",&n);
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        printf("Enter val and weigth of object no:%d ",i);
        scanf("%d",&val[i]);
        scanf("%d",&wt[i]);
    }

    int W;//capacity of knapsack
    printf("Enter the capcity of knapsack: ");
    scanf("%d",&W);

    int maxValue = knapsack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
