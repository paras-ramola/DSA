// Friend function in C++
#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    void setData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    void getData()
    {
        cout << "Your Number is " << a << "+" << b << "i" << endl;
    }
    // Below line means that non member-'sumcomplex' is allowed to do anyhting with the private data of this clas
    friend Complex sumcomplex(Complex o1, Complex o2); // declaring the friend function
};

Complex sumcomplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setData((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    Complex c1, c2, sum;
    c1.setData(2, 4);
    c1.getData();
    c2.setData(2, 2);
    c2.getData();
    sum = sumcomplex(c1, c2);
    sum.getData();
    // sum.sumcomplex(c1,c2);->It will give error because sumcomplex is not a part of the class "Complex",it is just an declaration

    return 0;
}

/*Properties of Friend Functon
1.Not in the scope of class.
2.Since it is not in the scope of the class,it cannot be called from the object of that class.eg->c1.sumcomplex==INVALID
3.Can be invoked without the help the object.
4.Usually contains object arguments.
5.Can be written inside the public or private section of the class
6.it cannot access the member directly by thier names and need object_name.member_name to access any member.

*/