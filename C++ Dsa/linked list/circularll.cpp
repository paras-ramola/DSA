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
        cout<<"deleting "<<this->data<<endl;
    }

};

void insertNode(Node*&tail,int element,int data){

    if(tail == NULL){
        Node* temp = new Node(data);
        temp -> next = temp;
        tail = temp;
    }
    else{
        //list is not empty
        //adding node after an element

        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;


//insert at end->making last element tail
        // if(curr==tail){
        //     tail=temp;
        // }
    }

}

void deleteNode(Node* &tail,int val){
    if(tail == NULL){
        cout<<"Linked list is empty!!"<<endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != val){
            prev = curr;
            curr = curr->next;
            
        }

        //Single node in list
        if(prev == curr){
            tail=NULL;
        }
        //deleting tail node
        else if(tail == curr){
            tail=prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    

}

void print(Node* &tail) {
    Node*temp = tail;
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    
    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while(temp != tail);

    cout << endl;
}

int  main(){
       Node* tail = NULL;//intially not pointing to anythinig
       //cant assign value as new Node(10) because then loop will run indenfinetily since curr->data!=elemt

   insertNode(tail, 5, 3);
   cout<<"Tail: "<<tail->data<<endl;
    print(tail);


//    insertNode(tail, 3, 5);
//    cout<<"Tail: "<<tail->data<<endl;
//    print(tail);
//    insertNode(tail, 3, 9);
// //    cout<<"Tail: "<<tail->data<<endl;
//    print(tail);
//    insertNode(tail, 5, 1);
// //    cout<<"Tail: "<<tail->data<<endl;
//    print(tail);
//    insertNode(tail, 9, 8);
// //    cout<<"Tail: "<<tail->data<<endl;
//    print(tail);

// //    deleteNode(tail,0);
   
//    deleteNode(tail,5);
//    print(tail);
//    deleteNode(tail,1);
//    print(tail);
   deleteNode(tail,3);
   print(tail);



}