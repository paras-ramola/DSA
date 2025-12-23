//Static Variable & staic Function

#include <iostream>
using namespace std;

class Employee
{
    int empId;
    int empsalary;
    static int count; // default value 0
public:
    void setdata(void);
    void getdata(void);

    static void getcount(void)//static function->it can access only other static member and other static function
    {
        cout << "the count is" << count << endl;
    }
};
int Employee::count; // This count is shared by every object
// This is shared by class and is a property of class,therfore it is known as Class Variable
// you can change the default value of count here.e.g=int Employee::count=100;

void Employee::setdata(void)
{
    cout << "Enter the Id of employee no:" << count << endl;
    cin >> empId;
    cout << "Enter The Sarlary" << endl;
    cin >> empsalary;
    count++;
}
void Employee::getdata(void)
{
    cout << "The Salary of Employee :" << empId << "is" << empsalary << endl;
}

int main()
{
    Employee rakesh, sujeh, rita;
    rakesh.setdata();
    Employee::getcount();
//   rakesh.getcount();
    sujeh.setdata();
    Employee::getcount();
    rita.setdata();
    Employee::getcount();
    rakesh.getdata();
    sujeh.getdata();
    rita.getdata();
    return 0;
}