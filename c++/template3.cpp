//class Template with Default argument

#include<iostream>
using namespace std;
template<class T1=int ,class T2=float>
class Paras{
    public:
    T1 a;
    T2 b;
    Paras(T1 x,T2 y){
        a=x;
        b=y;
    }
    void display(){
        cout<<"The Value of a is"<<a<<endl;
        cout<<"The Value of b is"<<b<<endl;
    }
};
int main(){
  Paras <>p(4,6.4);//<> are empty on default argumets
  p.display();
  cout<<endl;
  Paras <float ,char>p1(4.8,'i');
  p1.display();
return 0;
}