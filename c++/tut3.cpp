// To check a Binary Number

#include <iostream>
#include <string.h>
using namespace std;
class Binary
{
    string s;

public:
    void read(void);
    void check(void);
    void complement(void);
    void dispaly(void);
};

void Binary::read(void)
{
    cout << "Enter your Bonary Number" << endl;
    cin >> s;
}
void Binary::check(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s[i] != '1')
        {
            printf("Invalid Format");
            exit(0);
        }
    }
}
void Binary::dispaly(void)
{
    for (int i = 0; i < s.length(); i++)
    {
       cout<<i;
}
}

void Binary::complement(void)
{
for(int i=0;i<s.length();i++){
    if(s.at(i)=='0')
{
    s.at(i)='1';
}
    if(s.at(i)=='1')
{
    s.at(i)='0';
}

}
}
int main()
{
    Binary b1;
    b1.read();
    b1.check();
    b1.complement();
    b1.dispaly();
    return 0;
}