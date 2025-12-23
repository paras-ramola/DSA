//function template
#include<iostream>
using namespace std;

template<class T>
void swapp(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

template<class T1,class T2>
float funcAvg(T1 a,T2 b){
    float avg=(a+b)/2;
    return avg;
    }
int main(){
float a;
a=funcAvg(7,2.9);
cout<<"The avg is "<<a<<endl;
int x=5,y=7;
swapp(x,y);
cout<<x<<endl<<y;
return 0;
}