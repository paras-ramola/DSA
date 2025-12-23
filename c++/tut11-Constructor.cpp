// Constructor

/*Theory:
Constructor is a special memeber function with same name as the class.
It is used to initialize the objects of its class.
It is automatically invoked(called) whenever an object is created.
*/
#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    Complex(void); // Constructor declaration
    void printNumber()
    {
        cout << "Your number is " << a << "+" << b << "i" << endl;
    }
};
Complex::Complex(void)//Default consturctor
{
    a = 10;
    b = 90;
    //cout<<"Hello world";
}
int main()
{
    Complex c;
    c.printNumber();
    return 0;
}
/* Characteristics of constructors
1.It should be declared in the public section of the class.
2.They are automatically invoked whenever the object is created.
3.They cannot return values and do not have a return type.
4.It can have default arguments.
5.We cannot refer to their adress.
*/