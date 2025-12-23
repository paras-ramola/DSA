#include<iostream>
using namespace std;

// // single inheritance
// // one base class & one derived class

// class A{
// public:
//     void BaseClass(){
//         cout<<"Base Class"<<endl;
//     }
// };
// class B:public A{
//     public:
//     void DerClass(){
//     cout<<"Derived Class";
//     }
// };

// int main(){
//     A obj1;
//     obj1.BaseClass();
//     // obj1.DerClass();//Error
//     B obj2;
//     obj2.BaseClass();
//     obj2.DerClass();
// }


//Multilevel Inheritnance
//derived class is derived again into some another class

// class A{
//     public:
//             void BaseClass(){
//                 cout<<"Base Class 1"<<endl;
//             }
// };
// class B:public A{
//     public:
//             void DerClass1(){
//                 cout<<"Derived from A"<<endl;
//             }    
// };
// class C:public B{
//     public:
//             void DerClass2(){
//                 cout<<"Derived from -B,A"<<endl;
//             }    
// };

// int main(){
//     B obj2;
//     C obj3;
//     obj2.BaseClass();
//     obj2.DerClass1();

//     obj3.BaseClass();
//     obj3.DerClass1();
//     obj3.DerClass2();
// }

//Multiple Class
//A Derived Class with Multiple Base Class
// There is an ambiguity problem in multiple inheritance


// class A1{
//     public:
//         A1(){//constructor
//             cout<<"Base Class 1"<<endl;   
//         }
// };
// class A2{
//     public:
//         A2(){
//             cout<<"Base Class 2"<<endl;   
//         }
// };
// class B:public A2,public A1{
//     public:
//         B(){
//             cout<<"Derived Class "<<endl;   
//         }
// };
// int main(){
//     B obj;
//     return 0;
// }

// //Ambigous problem
// class A1{
//     public:
//         A1(){//constructor
//             cout<<"Base Class"<<endl;   
//         }
//         void work(){
//             cout<<"Working on Inheritance A1"<<endl;
//         }
// };
// class A2{
//     public:
//         A2(){
//             cout<<"Base Class"<<endl;   
//         }
//         void work(){
//             cout<<"Working on Inheritance A2"<<endl;
//         }
// };
// class B:public A2,public A1{
//     public:
//         B(){
//             cout<<"Derived Class "<<endl;   
//         }
// };
// int main(){
//     B obj;
//     // obj.work();//ambiguity problem->different func of same name
//     // 1.
//     obj.A1::work();
//     //2.
//     A1 obj1=obj;//obj of class B is assining all the values which are of class A1 to obj1 of class A1
//     obj1.work();
//     A2 obj2=obj;
//     obj2.work();
//     return 0;
// }


//Hierichal inheitance
// multiple derived class and one base class

// class Human{
//     public:
//     void purpose(){
//         cout<<"Finding Purpose"<<endl;
//     }
// };
// class Doctor:public Human{
//     public:
//     void Work(){cout<<"I am Saving Lives!!"<<endl;}
// };
// class Eng:public Human{
//     public:
//       void Work(){cout<<"I am making lives Eazzy"<<endl;}
// };

// int main(){
//     Doctor d;
//     d.purpose();
//     d.Work();
//     Eng e;
//     e.purpose();
//     e.Work();
// }

// hybrid inheritance
// combination of multiple and hierical inheritance

// class student{
//     public:
//     void study(){
//         cout<<"Students are both Girls and Boys"<<endl;
//     }
// };
// class female{};//Empty class
// class male{};
// class girl:public student,public female{};
// class boy:public student,public male{};

// int main(){
//     girl Sita;
//     Sita.study();
//     boy Ram;
//     Ram.study();
// }


// Multipath Inheritance
// 1.A derived class with two base class and these two base class have one common base class
//Diamond Problem ->human class(top class) is coming two times for paras (bottom class)->use virtual to solve ambiguity error

// class Human{
//     public:
//     void purpose(){
//         cout<<"Finding Purpose"<<endl;
//     }
// };
// class Doctor:public virtual Human{
//       public:
//     void Work(){cout<<"I am Saving Lives!!"<<endl;}  
// };
// class Eng:public virtual Human{
//         public:
//       void Work(){cout<<"I am making lives Eazzy"<<endl;}
// };
// class Paras:public Doctor,public Eng{};

// int main(){
//     Paras p;
//     p.purpose();
// //   p.work();//error
//     p.Eng::Work();
// }

//passing parameters to base class constructors
//constructor calling order ->Reverse->destructor calling

// class A{
//     public:
//     A(){
//         cout<<"Default Constructor of Class A"<<endl;
//     }
//     A(int x){
//         cout<<"ParameterizedConstructor of Class A "<<x<<endl;
//     }
//     ~A(){
//         cout<<"Destructor of class A"<<endl;
//     }
// };
// class B:public A{
//     public:
//     B():A(9){// class A will be called along with default constructr B
//         cout<<"Default Constructor of Class B"<<endl;
//     }
//     B(int y){
//     // B(int y):A(5){//to call parameterized constructor of A class
//         cout<<"ParameterizedConstructor of Class B "<<y<<endl;
//     }
//     ~B(){
//         cout<<"Destructor of class B"<<endl;
//     }
// };
// int main(){
//     B obj;
//     //B obj1(4);
// }

//virtual base class
// virtual isliye use krte h tki Result wli class do-do barr student class ko inherit na krle(while inheriting Academic and Sports class)
// class Student{
//     protected:
//         int roll_no;
//     public:
//         void set_number(int a){
//             roll_no=a;
//         }
//         void print_number(void){
//             cout<<"Your rollno is"<<roll_no<<endl;
//         }
// };
// class Academic:virtual public Student{
//     protected:
//         float maths,physics;
//     public:
//         void set_marks(float m1,float m2){
//             maths=m1;
//             physics=m2;
//         }
//         void print_marks(void){
//             cout<<"Maths:"<<maths<<endl;
//             cout<<"physics:"<<physics<<endl;
//         }
// };

// class Sports:virtual public Student{
//     protected:
//         float score;
//     public:
//         void set_score(float sc){
//             score=sc;
//         }
//         void print_score(void){
//             cout<<"P.T score:"<<score<<endl;
//         }
// };

// class Result:public Academic,public Sports{
//     private:
//         float total;
//     public:
//         void display(void){
//             total=maths+physics+score;
//             print_number();
//             print_marks();
//             print_score();
//             cout<<"Total score:"<<total<<endl;
//         }
// };
// int main(){
//     Result paras;
//     paras.set_number(47);
//     paras.set_marks(97,98);
//     paras.set_score(9);
//     paras.display();
//     return 0;


// }