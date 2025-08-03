#include <iostream>
// #include<queue>
using namespace std;

// Using STL
//  int main(){

//     queue<int> q;

//     q.push(1);
//     cout<<"Front: "<<q.front();
//     cout<<"Rear: "<<q.back()<<endl;
//     q.push(2);
//     cout<<"Front: "<<q.front();
//     cout<<"Rear: "<<q.back()<<endl;
//     q.push(3);
//     cout<<"Front: "<<q.front();
//     cout<<"Rear: "<<q.back()<<endl;

//     cout<<"Size: "<<q.size()<<endl;

//     q.pop();
//     cout<<"Front: "<<q.front();
//     cout<<"Rear: "<<q.back()<<endl;
//     q.pop();
//     cout<<"Front: "<<q.front();
//     cout<<"Rear: "<<q.back()<<endl;
//     q.pop();
//     cout<<"Front: "<<q.front();
//     cout<<"Rear: "<<q.back()<<endl;

// }

// Using Arrays

class queue
{
public:
    int *arr;
    int size;
    int qfront;
    int rear;

    queue(int s)
    {
        this->size = s;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full!!" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue()
    {
        if (qfront == rear)
        {
            cout << "Queue is Empty!!" << endl;
        }
        else
        {
            arr[qfront] = -1; // indicates item is poped
            qfront++;

            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            cout << "Queue is Empty!!" << endl;
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{

    queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
}