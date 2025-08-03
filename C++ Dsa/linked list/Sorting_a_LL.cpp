#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

// replacing value->using count method
Node *sort1(Node *head)
{
    Node *temp = head;
    int zero = 0, one = 0, two = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        temp = temp->next;
    }
    temp = head;
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}

// replacing value->using swap method
Node *sort2(Node *head)
{
    Node *i = head;
    Node *j = head;
    while (i->next != NULL)
    {
        while (j != NULL)
        {
            if (j->next != NULL)
            {
                if (j->data > j->next->data)
                {
                    swap(j->data, j->next->data);
                }
            }
            j = j->next;
        }
        j = head;
        i = i->next;
    }
    return head;
}

// replacing linked list

void insertAtTail(Node *&Tail, Node *curr)
{
    Tail->next = curr;
    Tail = curr;
}

Node *sort3(Node *head)
{
    Node *curr = head;

    // create dummyNodes for seperate list(0's,1's,2's)
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // creating seprate list for 0's,1's,2's
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merging the three lists
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else // 1's list is empty
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(1);
    Node *node3 = new Node(0);
    Node *node4 = new Node(2);
    Node *node5 = new Node(2);
    Node *node6 = new Node(0);
    Node *node7 = new Node(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    // node7->next = NULL;
    Node *head = node1;

    cout << "Before Sort" << endl;
    print(head);

    Node *ans = sort3(head);
    cout << "After Sort" << endl;
    print(ans);
}