#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
    ~Node(){
        cout<<"deleting "<<this->data<<endl;
    }

};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;

    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){  //edge case
         Node* temp = new Node(data);
         head = temp;
         tail = temp;
         return;
    }
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &head,Node* &tail,int data){
      if(tail == NULL){
         Node* temp = new Node(data);
         head = temp;
         tail = temp;
         return;
    }
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtMid(Node* &head,Node* &tail,int pos,int data){
    Node *temp = head;
    int cnt = 1;

    if(pos == 1){ //edge case
        insertAtHead(head,tail,data);
        return;
    }

    while(cnt < pos-1){
        cnt++;
        temp = temp -> next;
    }
    if(temp -> next == NULL){   // edge case
        insertAtTail(head,tail,data);
        return;
    }

    Node* temp2 = new Node(data);
    temp2 -> next = temp -> next;
    temp -> next -> prev = temp2;
    temp -> next = temp2;
    temp2 -> prev = temp;
}

void deleteNode(Node* &head,Node* &tail,int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;

        int cnt = 1;

        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr -> next == NULL){

            tail = curr -> prev;
            curr -> prev = NULL;
            prev -> next = NULL;

            delete curr;
            return;
        }

       prev -> next = curr -> next;
       curr -> next -> prev = curr -> prev;
       curr -> prev = NULL;
       curr -> next = NULL;

       delete curr;
    }
}

int main(){
    Node* node1=new Node(10);

    Node* head=node1;
    Node* tail=node1;

    print(head);

    insertAtHead(head,tail,30);
    print(head);
    insertAtHead(head,tail,0);
    print(head);

    insertAtTail(tail,tail,89);
    print(head);
    insertAtTail(tail,tail,99);
    print(head);

    insertAtMid(head,tail,1,50);
    print(head);
    insertAtMid(head,tail,7,34);
    print(head);
    deleteNode(head,tail,2);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,5);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    // cout<<"Length: "<<getLength(head)<<endl;

}