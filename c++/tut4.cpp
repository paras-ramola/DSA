// Objects Memory Allocation in c & using array in c++

#include <iostream>
using namespace std;

class shop
{

    int itemid[100];
    int itemprice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; };
    void setprice(void);
    void displayprice(void);
};
void shop::setprice(void)
{
    cout << "Entert the Id of your item no:" << counter + 1 << endl;
    cin >> itemid[counter];
    cout << "enter the price of your item:" << endl;
    cin >> itemprice[counter];
    counter++;
}

void shop::displayprice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item no:" << itemid[i] << "is" << itemprice[i] << endl;
    }
}

int main()
{
    shop s1;
    s1.initCounter();
    s1.setprice(); // you can instead use loop
    s1.setprice();
    s1.displayprice();

    return 0;
}