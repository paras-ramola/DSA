#include<iostream>
using namespace std;

int* firstlast(int arr[],int n,int key){
    static int ans[]={-1,-1};
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            ans[0]=i;
            while(arr[i+1]==key){
                i++;

            }
                ans[1]=i;
        }
    }
    return ans;
    
}

//Count occurence using first and last index

    int firstoccur(int nums[],int n,int target){

        int index=-1,start=0,end=n-1;

        while(start<=end){

            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                index=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return index;
    }

  int lastoccur(int nums[],int n,int target){

        int index=-1,start=0,end=n-1;

        while(start<=end){

        int mid=start+(end-start)/2;
            if(nums[mid]==target){
                index=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
                cout<<"End "<<end<<endl;
            }
        }
        return index;
    }




int getpivot(int arr[],int n){
    int start=0;
    int end=n-1;


    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}

int index(int arr[],int n,int key){
    int start=0;int end=n-1;

    while(start<end){
        int mid=start+(end-start)/2;
    
        if(key>=mid && key>arr[0]){
            end=mid;
        }
        else
            start=mid+1;
        }
        return end;
    }




    long long int SqrbinarySearch(long long int n){
        int start=0;
        int end=(n/2)+1;
        int ans=-1;
         while(start<=end){

            long long int mid=start+(end-start)/2;
            long long int sqr=mid*mid;

            if(sqr==n){
                return mid;
            }

            if(sqr<n){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
         }
         return ans;
    }

//Square root with more precision

    double sqrtprecision(double n,int precision,int tempsol){

        double factor=1;
        double ans=tempsol;

        for(int i=0;i<precision;i++){

            factor=factor/10;

            for(double j=ans;j*j<=n;j=j+factor){
                ans=j;
            }

        }
        return ans;
    }

int main(){
    int arr[]={4,5,6,7,0,1,2};

//First and last occurence
    // int * ans=firstlast(arr,9,4);
    // cout<<"First index :"<<ans[0]<<endl;
    // cout<<"Last index :"<<ans[1]<<endl;

//Number of occurence
    // int n1=firstoccur(arr,9,6);
    // int n2=lastoccur(arr,9,6);

    // cout<<"COunt "<<(n2-n1)+1<<endl;


//Pivot index
    // cout<<"Pivot Element :"<<getpivot(arr,5)<<endl;

    // cout<<"Index of pivot "<<index(arr,6,1)<<endl;

//Square root of a number

    int n ;
    cout<<"Enter the number";
    cin>>n;

    cout<<"square rooot without precision: "<<SqrbinarySearch(n)<<endl;

    int tempsol=SqrbinarySearch(n);

    cout<<"square rooot with precision: "<<sqrtprecision(n,3,tempsol);

}