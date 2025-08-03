#include<iostream>
using namespace std;

int binarySearch(int arr1[],int size,int key){

    int start=0;
    int end=size-1;
            int mid=start+(end-start)/2;

    while(start<=end){

    if(key==arr1[mid]){
        return mid;
    }

    if(key>arr1[mid]){
        start=mid+1;

    }
   else{
        end=mid-1;

    }
    mid=start+(end-start)/2;
    }
    return -1;

}

int reccurbinarySearch(int arr[],int start,int end,int key){


    while(start<=end){
            int mid=start+(end-start)/2;
        if(arr[mid]==key){
           return mid;
    }
        if(key>arr[mid]){
            return reccurbinarySearch(arr,mid+1,end,key);
        }
        else{
            return reccurbinarySearch(arr,0,mid-1,key);
        }

    }
    return -1;
}

int main(){
    int arr1[]={2,4,5,9,13,17,23,28,30,37,45,57,63};

    int key;
    cin>>key;
    int index=binarySearch(arr1,13,key);
    // int index=reccurbinarySearch(arr1,0,12,key);
    cout<<"Element found at index "<<index<<endl;
}