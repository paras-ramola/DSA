//Some examples of Friend Function
//eg1:
/*
#include <iostream>
using namespace std;
class Y; // forward declaration
class X
{
    int data;

public:
    void setValue(int value)
    {
        data = value;
    }
    friend void add(X, Y);
};
class Y
{
    int num;

public:
    void setValue(int value)
    {
        num = value;
    }
    friend void add(X, Y);
};

void add(X o1, Y o2)
{
    cout << "The sum of X and Y is:" << o1.data + o2.num << endl;
}
int main()
{
    X x1;
    x1.setValue(3);
    Y y1;
    y1.setValue(4);
    add(x1, y1);
    return 0;
}*/

//eg2:
#include<iostream>
using namespace std;
class Y;
class X{
    int x;
    public:
    void setValues(int value){
        x=value;
    }
    void display(void){
        cout<<"Value of 'x' is:"<<x<<endl;
    }
   friend void exchange(X &,Y &);//call by reference
};
class Y{
    int y;
    public:
    void setValues(int value){
        y=value;
    }
     void display(void){
        cout<<"Value of 'y' is:"<<y<<endl;
    }
    friend void exchange(X &,Y &);
};


void exchange(X &o1,Y &o2){
    int temp=o1.x;
    o1.x=o2.y;
    o2.y=temp;
}
int main(){
    X x1;
    x1.setValues(78);
    x1.display();
    Y y1;
    y1.setValues(80);
    y1.display();
    exchange(x1,y1);
    x1.display();
    y1.display();
return 0;
}