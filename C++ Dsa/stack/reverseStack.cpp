#include <iostream>
using namespace std;

class stack
{
public:
    char *arr;
    int size;
    int top;

    stack(int s)
    {
        this->size = s;
        arr = new char[size];
        top = -1;
    }
    void push(char val)
    {
        if (top < (size - 1))
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Overflow" << endl;
            return;
        }
    }
    char pop()
    {
        if (top >= 0)
        {
            char a = arr[top];
            cout << "Item deleted: " << arr[top] << endl;
            top--;
            return a;
        }
        else
        {
            cout << "Underflow" << endl;
            return -1;
        }
    }
    void print()
    {
        if (top == -1)
        {
            cout << "Underflow!!!" << endl;
        }
        int temp = -1;
        while (temp >= 0)
        {
            cout << arr[temp] << "  ";
            temp--;
        }
        cout << endl;
    }
};
int main()
{
    string original = "HELLo";

    int n = original.size();

    stack st(n);
    for (int i = 0; i < n; i++)
    {
        st.push(original[i]);
    }

    string rev = "";
    for (int i = 0; i < n; i++)
    {
        char a = st.pop();
        rev.push_back(a);
    }

    cout << rev;
}
