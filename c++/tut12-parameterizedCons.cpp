//Parameterised constructor
 //eg1:
/*
#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    Complex(int x,int y); // Constructor declaration
    void printNumber()
    {
        cout << "Your number is " << a << "+" << b << "i" << endl;
    }
};
Complex::Complex(int x,int y)//Parameterised consturctor
{
    a = x;
    b = y;
}
int main()
{
    //Implicit call
    Complex a(4,8);

    //Explicit call
    Complex b=Complex(5,7);
    
    a.printNumber();
    b.printNumber();
    return 0;
}
*/

//eg2:
#include<iostream>
using namespace std;
class Point{
    int x,y;
    public:
    Point(int a,int b){
        x=a;
        y=b;
    }
    void displayPoint(void){
        cout<<"The point is ("<<x<<","<<y<<")"<<endl;
    }
};
int main(){
  Point p(1,1);
  p.displayPoint();
  Point q(8,-2);
  q.displayPoint();  
return 0;
}
