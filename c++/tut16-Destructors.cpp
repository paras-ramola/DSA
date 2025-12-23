// Destructor
//never takes any argument nor does it return any value
#include <iostream>
using namespace std;
int count = 0;
class Number
{
public:
    Number()//Constructor->called when object is created
    {
        count++;
        cout << "This is a time when constructor is called for object number " << count << endl;
    }
    ~Number()//destructor->called when object is destroyed
    {
        cout << "This ia a time when destructor is called for object number " << count << endl;
        count--;
    }
};
int main()
{
    cout << "We are inside our main function" << endl;
    cout << "creating first object" << endl;
    Number n1;
    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects" << endl;
        Number n2, n3;
        cout << "Exiting the block" << endl;
    }
    cout << "Back to main" << endl;
    return 0;
}