#include <iostream>
// #include<deque>
using namespace std;

// int main(){
//     deque<int> d;
//     d.push_front(4);
//     d.push_front(8);
//     d.push_back(19);

//     d.pop_front();

//     cout<<d.size()<<endl;
//     cout<<d.front()<<endl;
//     cout<<d.back()<<endl;
// }

class deque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    deque(int s)
    {
        this->size = s;
        arr = new int[s];
        front = rear = -1;
    }

    void push_front(int data)
    {
        if ((front == 0 && rear == (size - 1)) || (front == (rear + 1) % size))
        {
            cout << "Queue is FULL" << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != (size - 1))
        {
            front = (size - 1);
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }
    void push_back(int data)
    {
        if ((front == 0 && rear == (size - 1)) || (front == (rear + 1) % size))
        {
            cout << "Queue is FULL" << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == (size - 1) && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pop_front()
    {
        if (front == -1)
        {
            cout << "Queue is EMPTY!!!" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == (size - 1))
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void pop_back()
    {
        if (front == -1)
        {
            cout << "Queue is EMPTY!!!" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = (size - 1);
        }
        else
        {
            rear--;
        }
    }
    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[rear];
    }
};

int main()
{

    deque d(5);

    d.push_front(8);
    d.push_back(19);

    d.pop_front();

    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
}