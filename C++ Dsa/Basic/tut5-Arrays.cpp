#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}
int find_max(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        // if(arr[i]>max){
        //     max=arr[i];
        // }
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
int find_min(int arr[],int n){
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        // if(arr[i]<min){
        //     min=arr[i];
        // }
        mini=min(mini,arr[i]);
    }
    return mini;
}

//Linear Search
bool search(int arr[],int n, int key){
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            return 1;
        }
    }
        return 0;
}


void swap(int &x,int &y){
        int temp=x;
        x=y;
        y=temp;
}
//reverse array
void rev(int arr[],int n){
//1.
    // for(int i=0;i<n/2;i++){
    //     int temp=arr[i];
    //     arr[i]=arr[n-i-1];
    //     arr[n-i-1]=temp;
    // }

//2.
int start=0;int end=n-1;
while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
}
}





int main(){
    //TO intialize entire array to zero
    int a[1000]={0};
    printArray(a,1000);

    cout<<"2 Array"<<endl;
    int b[1000]={1};//Wrong Method
      printArray(b,1000);

//to intialze entire array to any value
    cout<<"3rd Array"<<endl;
    fill_n(a,1000,4);
    printArray(a,1000);

    int third[15]={2,7};
     printArray(third,15);
//  TO find size of an array
     int size=sizeof(third)/sizeof(int);
     cout<<"Size of Array "<<size<<endl;

int demo[]={0,2,3,4,1,5,7,-2,9,18,0,65};
cout<<"Maximum Element: "<<find_max(demo,12)<<endl;
cout<<"Minimum Element: "<<find_min(demo,12)<<endl;

//Homework:Sum of element

int n;
cout<<"Enter size";
cin>>n;
int hw[100];
for(int i=0;i<n;i++){
    cout<<"Enter "<<i<<" element"<<endl;
    cin>>hw[i];
}
int sum=0;
for(int i=0;i<n;i++){
    sum=sum+hw[i];
}
cout<<"sum : "<<sum<<endl;

//Linear Search
int arr[10]={5,7,-4,3,6,2,0};
int key;
cout<<"Enter key to search"<<endl;
cin>>key;

bool found=search(arr,7,key);
if(found){
    cout<<"key found"<<endl;
}
else{
    cout<<"Not found";
}


//Reverse an array
cout<<"Original Array"<<endl;
printArray(arr,7);
rev(arr,7);
cout<<"reverse Array:"<<endl;
printArray(arr,7);
}