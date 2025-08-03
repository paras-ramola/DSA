#include <iostream>
using namespace std;

class queue
{

    int *arr;
    int size;
    int qfront;
    int rear;

public:
    queue(int s)
    {
        this->size = s;
        arr = new int[s];
        qfront = rear = -1;
    }

    void enqueue(int data)
    {

        if ((qfront == 0 && rear == (size - 1)) || (qfront == (rear + 1) % size)) // Queue is FULL
        {
            cout << "Queue is FULL!!" << endl;
        }
        else if (rear == -1) // first element  to PUSH in Queue
        {
            qfront = rear = 0;
        }
        else if (rear == (size - 1) && qfront != 0) // rear reached the end of Queue
        {
            rear = 0;
        }
        else // normal
        {
            rear++;
        }
        arr[rear] = data;
    }
    void dequeue()
    {
        if (qfront == -1)
        { // Queue is Empty
            cout << "Queue is Empty!!" << endl;
        }
        else if (qfront == rear) // last element to POP
        {
            qfront = rear = -1;
        }
        else if (qfront == (size - 1))
        { // qfront reached the end
            qfront = 0;
        }
        else
        {
            qfront++;
        }
    }
};

int main()
{

    queue q(5);

    q.enqueue(1);
    q.enqueue(2);
}
