#include<iostream>
using namespace std;
int main(){
    int a=2;
    int b=4;

//Bitwise Operator
    cout<<"a&b "<< (a&b) << endl;
    cout<<"a|b "<< (a|b) << endl;
    cout<<"~a "<< (~a) << endl;
    cout<<"a^b "<< (a^b) << endl;

//Right Shift Operator
cout<< (17>>1)<<endl;
cout<<(17>>2)<<endl;
//Left Shift Operator
cout<<(19<<1)<<endl;
cout<<(19<<2)<<endl;

//Pre/Post Increment/Decrement Operator
int i=7;
cout<<(++i)<<endl;
cout<<(i++)<<endl;
cout<<(i--)<<endl;
cout<<(--i)<<endl;


// int n;
// cout<<"Enter n:";
// cin>>n;

//Fibonacci Series
// int a1=0,b1=1;
// cout<<a1<<"\t"<<b1<<"\t";//First two numbers
// for(int i=3;i<=n;i++){
// int sum=a1+b1;
//  cout<<sum<<"\t";
// a1=b1;
// b1=sum;
// }
// cout<<endl;

//Prime Number or not

// bool prime=true;
// for(int i=2;i<=n/2;i++){
//     if(n%i==0){
//         prime=false;
//         break;
//     }
// }
// if(prime){
//     cout<<"Prime Number"<<endl;
// }
// else{
//     cout<<"Not a Prime Number"<<endl;
// }

//continue

// for(int i=0;i<n;i++){
//     cout<<"HI"<<endl;
//     cout<<"Hello"<<endl;
//     continue;
//     cout<<"ok"<<endl;
// }

int a2 ;
cout<<a2;
}