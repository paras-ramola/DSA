 #include<iostream>
 using namespace std;
 
class Number{
    int a;
public:
    Number(){
    }
    Number(int num){
        a=num;
    }
    Number(Number &obj){
        cout<<"Copy Constructor called"<<endl;
        a=obj.a;
    }
    void display(){
        cout<<"Number is :"<<a<<endl;
    }
};
 int main(){
    Number x,y,z(34);
    x.display();
    z.display();
    Number z3=x;
    z3.display();
 return 0;
 }