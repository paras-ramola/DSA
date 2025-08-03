#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int value=this->data;

        cout<<"Memory freed for value "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtMid(Node* &head, Node* &tail,int pos, int data){

//insertion at starting
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    Node* temp1 = head;
    int cnt = 1;
    while(cnt < pos-1){
        temp1 = temp1 -> next;
        cnt++;
    }

//insertion at end
    if(temp1 -> next == NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* temp2 = new Node(data);
    temp2 -> next = temp1 -> next;
    temp1 -> next = temp2;
}

void deleteNode(Node* &head,Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node *prev = NULL;
        Node* curr = head;
        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr -> next == NULL){
            tail=prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }

}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 =new Node(9);
    
    Node* head=node1;
    Node*tail=head;

    // print(head);
    // insertAtHead(head,8);
    // print(head);
    // insertAtHead(head,7);
    // print(head);
    // insertAtTail(tail,10);
    // print(head);
    insertAtTail(tail,11);
    print(head);
    insertAtMid(head,tail,3,15);
    print(head);
    insertAtMid(head,tail,1,15);
    print(head);
    insertAtMid(head,tail,5,14);
    print(head);
    deleteNode(head,tail,2);
    print(head);
    deleteNode(head,tail,4);
    print(head);
    cout<<"tail "<<tail->data<<endl;
}