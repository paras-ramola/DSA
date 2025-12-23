// Copy Constructor
#include <iostream>
using namespace std;
class Number
{
    int a;

public:
    // Number(){} ->Blank Constructor
    Number()
    { // you can store default value inside blank constuctor
        a = 0;//default Value
    }
    Number(int num)
    {
        a = num;
    }
    // Copy Constructor:when no copy constructor is provided , compiler supplies its own copy constructor,(this means you can copy a constuctor without using copy constructor)
    Number(Number &obj)
    {
        cout << "Copy Constructor is called" << endl;
        a = obj.a;
    }
    void display()
    {
        cout << "The number for this object is" << a << endl;
    }
};
int main()
{
    Number x, y, z(34), z2;
    x.display();  // 0
    y.display();  // 0
    z.display();  // 34
    Number z1(x); // copy constructor invoked
    z1.display(); // 0

    z2 = z; // copy constructor not called (kyunki ye(z2) already bn gya h)
    z2.display();

    Number z3 = z; // copy constructor is called
    z3.display();
    return 0;
}
/*NOTE:1.copy constructor will be called as long as it is used by a newly created object 
2.If there is no copy constructor made by user compiler will provide its own copy constructor
*/