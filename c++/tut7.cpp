// passing Objects as Function Arguments
#include<iostream>
using namespace std;
class complex{
    int a;
    int b;
    public:
    void setData(int v1,int v2){
        a=v1;
        b=v2;
    }
    void sumData(complex o1,complex o2){//o1&o2 are objects of class complex
        a=o1.a+o2.a;
        b=o1.b+o2.b;
    }

    void printData(void){
        cout<<"The complex number is: "<<a<<"+"<<b<<"i"<<endl;
    }
};
int main(){
complex c1,c2,c3;
c1.setData(1,4);
c1.printData();
c2.setData(3,2);
c2.printData();
c3.sumData(c1,c2);
c3.printData();
return 0;
}