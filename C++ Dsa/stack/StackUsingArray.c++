#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (top < size-1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack is FULL!!!" << endl;
            return;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            cout << "Item to delted: " << arr[top] << endl;
            top--;
        }
        else
        {
            cout << "Stack is Empty!!!" << endl;
            return;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty!!!" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }

    }
    void print()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!!!" << endl;
            return;
        }
        int temp = top;
        while (temp != -1)
        {
            cout << arr[temp] << " ";
            temp--;
        }
        cout << endl;
    }
};

int main()
{

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(5);

    st.print();
    st.pop();
    st.pop();
    st.print();
    st.pop();
    cout<<"Peeek"<<st.peek()<<endl;
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
}