// *watch polymorphism file ->example before this
#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base;
        virtual void display(){
            cout<<"1.Displaying the BaseClass variable"<<var_base<<endl;
        }
};
class DerivedClass:public BaseClass{
    public:
     int var_derived;
     void display(){
            cout<<"2.Displaying the BaseClass variable"<<var_base<<endl;
            cout<<"2.Displaying the DerivedClass variable"<<var_derived<<endl;
        }
};


int main(){
BaseClass obj_base;
DerivedClass obj_derived;
BaseClass *base_class_pointer;//pointer of BaseClass
base_class_pointer=&obj_derived;//pointing to DerivedClass
base_class_pointer->display();//without virtual->OUTPUT:display of BaseClass pointer
//with virtual->OUTPUT:display of DerivedClass
base_class_pointer=&obj_base;
base_class_pointer->display();
DerivedClass *derived_class_pointer;
// derived_class_pointer=&obj_base;//ERROR
derived_class_pointer=&obj_derived;
derived_class_pointer->display();
return 0;
}

// //Eg:
// class Youtube
// {
// protected:
//     string title;
//     float rating;
// public:
//     Youtube(string s,float r){
//         title=s;
//         rating=r;
//     }
//     virtual void display(){}//VIRTUAL FUNCTON
// };

// class ytVideo:public Youtube{
//     float videolength;
//     public:
//     ytVideo(string s,float r,float vl):Youtube(s,r){
//         videolength=vl;
//     }
//     void display(){
//         cout<<"Title:"<<title<<endl;
//         cout<<"Rating:"<<rating<<endl;
//         cout<<"Duration"<<videolength<<"minutes"<<endl;
//     }
// };
// class ytText:public Youtube{
//     int words;
//     public:
//     ytText(string s,float r,int w):Youtube(s,r){
//         words=w;
//     }
//     void display(){
//         cout<<"Title:"<<title<<endl;
//         cout<<"Rating:"<<rating<<endl;
//         cout<<"Text Length"<<words<<"words"<<endl;
//     }
// };


// int main(){
//     string title;
//     float rating,vlen;
//     int wrd;

// // for ytVideo
//     title="Virtual Functions in C++";
//     rating=4.78;
//     vlen=7.9;
//     ytVideo v1(title,rating,vlen);
//     // v1.display();

// //For ytText
//     title="Virtual Functions in C++";
//     rating=4.88;
//     wrd=897;
//     ytText t1(title,rating,wrd);
//     // t1.display();

// Youtube *yt[2];
// yt[0]=&v1;
// yt[1]=&t1;
   
// yt[0]->display();   
// yt[1]->display();   
// }

// RULES FOR VIRTUAL FUNCTION
//1.They cannot be Static
//2.They are accesed by object pointers
//3.Virtual fuctions can be friend of another class
//4.A virtual function in base class might not be used
//5.If a virtual function is defiened in a base class,there is no neccesity of definening it in the derived class

