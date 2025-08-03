#include<iostream>
#include <algorithm>
using namespace std;



void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}

void swapAlternate(int arr[],int n){

//1.
// int i=0,j=1;
// while(i<n && j<n){
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;

//     i=j+1;
//     j=j+2;
// }

// 2.
for(int i=0;i<n;i=i+2){
    if(i+1<n){
        swap(arr[i],arr[i+1]);
    }
}
}
//3.Find Unique element in array
int findUnique(int *arr, int size)
{
int ans=0;
for(int i=0;i<size;i++){
    ans=ans^arr[i];
}
return ans;
};

    int findDuplicate(int arr[],int n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^arr[i];
        }
        for(int i=1;i<n;i++){
            ans=ans^i;
        }
        return ans;
    }

void pairsum(int arr[],int n,int sum){
        int temp[100];
        int ans[100];
        int k=0;
        int l=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==sum){
                    temp[k++]=min(arr[i],arr[j]);
                    temp[k++]=max(arr[i],arr[j]);
    }
                }
            }
            cout<<"Pair Sum"<<endl;
        for(int i = 0; i < k; i++) {
            cout<<temp[i]<<"\t";
        }

    };

    void threeSum(int nums[],int n,int sum) {
        int ans[100];
        int m=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==sum){
                        ans[m++]=nums[i];
                        ans[m++]=nums[j];
                        ans[m++]=nums[k];

                    }
                }
            }
        }
        cout<<"three sum"<<endl;
        for(int i=0;i<m;i++){
        cout<<ans[i]<<"\t";
        }
    }


    void swap(int *a,int *b){
                int temp=*a;
                *a=*b;
                *b=temp;
            
        }
    void sort012(int arr[],int n){

    //using sort function
        // sort(arr,arr+n);

    //using sorting algo
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]>arr[j]){
    //             int temp=arr[i];
    //             arr[i]=arr[j];
    //             arr[j]=temp;
    //         }
    //     }
    // }

    // 
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
 
    //Print function
    cout<<"Sort 0,1,2"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }

    }



int main(){
    int size;
    cout<<"Enter the size"<<endl;
    cin>>size;

  int arr[100];

  for(int i=0;i<size;i++){
    cin>>arr[i];
  }

//Swap Alternate
    // cout<<"Previous Array: ";
    // print(arr,size);
    // cout<<endl;

    // swapAlternate(arr,size);

    // cout<<"New Array: ";
    // print(arr,size);
    // cout<<endl;

//find unique
    cout<<"Unique Element: "<<findUnique(arr,size)<<endl;

//findDuplicate
    cout<<"Duplicate Element: "<<findDuplicate(arr,size)<<endl;;
  
//Pair Sum
    pairsum(arr,size,5);
    cout<<endl;

//triplets
    threeSum(arr,size,10);

//sort 0,1,2
    sort012(arr,size);

}