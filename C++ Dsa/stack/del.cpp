// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class SpecialStack
{
public:
    vector<int> arr;
    int topIndex = -1;
    int minData = 9999;

    stack<int> st;

    void push(int data)
    {
        topIndex++;
        arr.push_back(data);
        minData = min(minData, data);
        st.push(minData);
    }

    void pop()
    {
        if (!arr.empty())
        {
            arr.pop_back();
            topIndex--;
            st.pop();
            if (!st.empty())
            {

                minData = st.top();
            }
            else
            {

                minData = 9999;
            }
        }
    }

    int top()
    {
        if (!arr.empty())
        {
            return arr.back();
        }
        return -1;
    }

    int getMin()
    {
        return st.top();
    }
};

int main()
{
    SpecialStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << "Min" << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "Min" << s.getMin() << endl;
}
