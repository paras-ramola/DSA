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
    ~Node()
    {
        int value = this->data;

        cout << "Memory freed for value " << value << endl;
    }
};

// Approach1:
bool isCycle(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        // Cycle is present
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Approach2: Flyod's Cycle Detection
Node *flyodsCycle(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            cout << "slow and fast meeet at " << slow->data << endl;
            return slow;
        }
    }
    return NULL; // NULL means loop is not present
}

// Find the starting Node of a the Cycle/Loop in a Linked List
Node *startingNodeofCycle(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = flyodsCycle(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Note: we pass head  and still we see changes in main ll ,this is beccause it creates a copy of pointer variable not the data it points to so even if head is passed by value the pointer still points to the same data  as orginal one.


//Removing loop from linked List
void removeLoop(Node *head)
{

    Node *startingNode = startingNodeofCycle(head);

    Node *slow = startingNode->next;

    while (slow->next != startingNode)
    {
        slow = slow->next;
    }

    slow->next = NULL;
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
    Node *node2 = new Node(2);
    Node *node3 = new Node(5);
    Node *node4 = new Node(4);
    Node *node5 = new Node(3);
    Node *node6 = new Node(8);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node3;

    Node *head = node1;
    // print(head);

    if (flyodsCycle(head))
    {
        cout << "Cycle is Present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    Node *startOfLoop = startingNodeofCycle(head);
    cout << "starting Node of Loop is " << startOfLoop->data << endl;

    removeLoop(head);

    if (flyodsCycle(head))
    {
        cout << "Cycle is Present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    print(head);
}