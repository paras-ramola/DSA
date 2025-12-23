//Inheritance in C++:/theory
/*
The concept of Resuability in C++ is supported in Inheritance.
We can reuse the properties of an existing class by inherting from it.
The existing class is called as the Base Class.
The new class which is inherited is called Derived Class.
Resusing class saves time and money. 
*/
/*Types of Inheritance:
1.Single Inheritance:A derived class with only one base. A->B
2.Multiple Inheritance : A derived class with more than one base class.A->c<-B
3.Hierarchical Inheritance:several derived class from a single base class.
4.Multilevel Inheritance :Deriving a class from already derived class.
5.Hybrid Inheritance :combination of Multiple inheritance and multilevel inheritance.
A class is derived from two classes as in multiple inheritance.
However,one of the parent class is not a Base class.
*/

//Derived class:Syntax
/*
class {{derivedClass_name}}:{{viblity-mode}}{{baseClass mode}}
{
class members/methods/etc..
}
Note:
1.Default visiblity mode is private
2.Public visiblity mode:Public member of the base class class become the public member of derived class.
3.Private visiblity mode:Public member of the base class class become the private member of derived class.
4.Private member are never inherited.
*/