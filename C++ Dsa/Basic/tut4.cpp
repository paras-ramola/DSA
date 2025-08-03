#include <iostream>
using namespace std;

//even odd
bool isEven(int n){
    if(n&1){
        return 0;
    }
    return 1;
}

//Factorial
int fact(int n){
    int fac=1;
  for(int i=1;i<=n;i++){
    fac=fac*i;
  }
  return fac;
}
int nCr(int n,int c){
    int num=fact(n);
    int denum=fact(c)*fact(n-c);
    return num/denum;
}

//Homework
//Ap
int Ap(int n){
    return (3*n+7);
}

//Number of set bits
int setBits(int a,int b){
    int count=0;
    while(a!=0){
        int bit1=a&1;
        if(bit1==1){
            count++;
        }
        a=a>>1;
    }
    while(b!=0){
        int bit2=b&1;
        if(bit2==1){
            count++;
        }
        b=b>>1;
    }
    
    return count;
}

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
   return fibonacci(n-1)+fibonacci(n-2);
}


int main(){
// int num;

// while(1<2){
// cin>>num;
// switch( num ){
//     case 1:cout<<"case 1"<<endl;
//     break;
//     case 2:
//        continue;
//     case 3:cout<<"Hello"<<endl;break;
//     break;
//     case 4:exit(0);
//     default:cout<<"break"<<endl;
//     break;
// }
// }

//MINI-Calculator
// int num1,num2;
// int choice;

// do{cout<<"enter value 1 and value2"<<endl;
// cin>>num1>>num2;
// cout<<"Enter 1-Add"<<endl;
// cout<<"Enter 2-Subtract"<<endl;
// cout<<"Enter 3-Multiply"<<endl;
// cout<<"Enter 4-Divide"<<endl;
// cout<<"Any Number-Exit";
// cin>>choice;
// switch(choice){
//     case 1:cout<<"Add: "<<num1+num2<<endl;
//     break;
//     case 2:cout<<"Subtract: "<<num1-num2<<endl;
//     break;
//     case 3:cout<<"Multiply: "<<num1*num2<<endl;
//     break;
//     case 4:cout<<"Divide: "<<num1/num2<<endl;
//     break;
//     default:exit(1);

// }
// }while(1);


// //Money Change
// int n, x=0,y=0,z=0,a=0;

//     cout << "Enter the amount" << endl;
//     cin >> n;

//     switch (1)
//     {
//     case 1:
//         x += n/100;
//         n %= 100;
//         cout << x << " 100 Rupee Notes" << endl;
    
//     case 2:
//         y += n/50;
//         n %= 50;
//         cout << y << " 50 Rupee Notes" << endl;

//     case 3:
//         z += n/20;
//         n %= 20;
//         cout << z << " 20 Rupee Notes" << endl;

//     case 4:
//         a += n/1;
//         n %= 1;
//         cout << a << " 1 Rupee Notes" << endl;
 
//     default:
//         break;
//     }

//Functions
//even 0dd
int n=5;
bool ans=isEven(n);
if(ans){
cout<<"Number is even"<<endl;
}
else{
    cout<<"Number is odd"<<endl;
}

//nCr
int ans1=nCr(0,0);
cout<<"Factorial :"<<ans1<<endl;


//Homework
int n1=3;
int ans2=Ap(n1);
cout<<"Ap of "<<n1<<" term is"<<ans2<<endl;

//
int a=2147483645,b=3;
int ans3=setBits(a,b);
cout<<"Number of set bits(1) in "<<a<<" & "<<b<<" is "<<ans3<<endl;

//fibonacci
cout<<"fibonacci of"<<fibonacci(4)<<endl;

}

