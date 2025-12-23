//we can't delete derived class object using base class pointer with non-virtual destructor.to delte derived class object we use virtual destructor
//Virtual constructor does not exist

#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<"Base Class Constructor"<<endl;
    }
    virtual ~Base(){
        cout<<"Base Class Destructor"<<endl;
    }
};

class Derived:public Base{
    public:
    Derived(){
        cout<<"Derived Class Constructor"<<endl;
    }
    ~Derived(){
        cout<<"Derived Class Destructor"<<endl;
    }
};

int main(){
    // Base *b1=new Base();//Base Class Construcor
    // delete b1;//Base Class Destructor

   Base *b1=new Derived();
    delete b1;
}




// You should use 'new' when you wish an object to remain in existence until you delete it. If you do not use 'new' then the object will be destroyed when it goes out of scope.