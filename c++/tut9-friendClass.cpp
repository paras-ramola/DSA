#include <iostream>
using namespace std;
// Forward Declaration
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumRealcomplex(Complex, Complex);
    int sumCompcomplex(Complex, Complex);
};
class Complex
{
    int a, b;
    //Individually Declaring functiom as Friend
    // friend int Calculator::sumRealcomplex(Complex, Complex);
    // friend int Calculator::sumCompcomplex(Complex, Complex);

    //Alter:Declaring the entire calculator as Friend Class
    friend class Calculator;

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
};

int Calculator::sumRealcomplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}
int Calculator::sumCompcomplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex c1, c2;
    c1.setData(2, 4);
    c2.setData(3, 2);
    Calculator calc;
    int res1 = calc.sumRealcomplex(c1, c2);
    cout << "The sum of real part of c1 &c2 is" << res1 << endl;
    int res2=calc.sumCompcomplex(c1,c2);
    cout<<"The sum of complex part of c1& c2 is"<<res2<<endl;
    return 0;
}
// to give multiple function of a class permisson to acces the data member of another class we use friend class Function