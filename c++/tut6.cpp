// Array of Objects
#include <iostream>
using namespace std;
class Employee
{
    int id;
    int salary;

public:
    void setId(void)
    {
        cout << "Enter the id of Employee:" << endl;
        cin >> id;
        cout << "Enter the Salary of employee:" << endl;
        cin >> salary;
    }
    void getId(void)
    {
        cout << "The salary of employee:" << id << "is" << salary << endl;
    }
};
int main()
{
    // Employee harry, rohan, lavish;
    // harry.setId();
    // harry.getId();
    // rohan.setId();
    // rohan.getId();
    // lavish.setId();
    // lavish.getId();
    Employee e1[4];//Array of objects
    for (int  i = 0; i <4; i++)
    {
        e1[i].setId();
        e1[i].getId();
    }
    

    return 0;
}