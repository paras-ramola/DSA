// polymorphism
// -one name and multiple forms
// -eg.function overloading,operator overloading,virtual function
//Two types
//1.Compile Time Polymorphism:decision le liye jata h ki konsa function run hone wala h(ise 'early binding' ya 'static binding bhi kehte h')aur use object se bind kr dete h
// complie time polymorphism can be achived using:
//   1.1.Function Overlaoding
//   1.2.Operator Overloading
//2.Run Time Polymorphism:code k run hone k baad vo dekhta h ki konsa  function run hoga,isme binding nhi hoti h,decision pointer k type ko dekher liya jata h
//Runtime Polymorphism can be achived using:
//   1.Virtual Function

//Runtime
// Pointer to Derived Classes

#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base;
        void display(){
            cout<<"Displaying the BaseClass variable"<<var_base<<endl;
        }
};
class DerivedClass:public BaseClass{
    public:
     int var_derived;
     void display(){
            cout<<"Displaying the BaseClass variable"<<var_base<<endl;
            cout<<"Displaying the DerivedClass variable"<<var_derived<<endl;
        }
};
int main(){
    BaseClass *base_class_pointer;//BaseClass k object ko point krega
    BaseClass obj_base;//base class k a object
    DerivedClass obj_derived;//DerivedClass ka object
    base_class_pointer=&obj_derived;// BaseClass k pointer ko point kra dia DerivedClass k object se 
    // base_class_pointer se agr hum display function call krenge to vo BaseClass k display ko hi call krega ,kyunki vo BaseClass ka hi  pointer h
    base_class_pointer->var_base=45;
    // base_class_pointer->var_derived=45;//error
    base_class_pointer->display();

    DerivedClass *derived_class_pointer;
    derived_class_pointer=&obj_derived;
    derived_class_pointer->var_base=9840;
    derived_class_pointer->var_derived=90;
    derived_class_pointer->display();
}
