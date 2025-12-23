#include<iostream>
using namespace std;

class Employee
{
private:
int a,b,c;
public:
int d,e;
void setdata(int a1,int b1,int c1){
a=a1;
b=b1;
c=c1;
}
void printdata()
{
   cout<<"the value of a is:"<<a<<endl<<b<<endl<<c<<endl; 
cout<<"the value of b is:"<<b<<endl;
cout<<"the value of c is:"<<c<<endl;
cout<<"the value of d is:"<<d<<endl;
cout<<"the value of e is:"<<e<<endl;

}};



int main(){
   
    Employee e1;
     e1.d=9;
    e1.e=89;
     
    e1.setdata(1,2,4);
   e1.printdata();
    return 0;
}