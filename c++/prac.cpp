#include<iostream>
using namespace std;
// namespace n1{
//     int x=2;
//     void fun(){
//         cout<<"first"<<endl;
//     }
// }
// namespace n2{
//     int x=9;
//     void fun(){
//         cout<<"second";
//     }
// }
// // int main(){
// //     n1::fun();//first
// //     n2::fun();//second
// // }
// using namespace n1;
// int main(){
//     fun();//first
// }
// int main() 
// { 
// int arr[5]={10, 0, 20, 0, 30}; //creating and initializing array 
//  //traversing array 
//  for (int i: arr) 
//  { 
//  cout<<i<<"\n"; 
//  } 
// } 
// int change(int *p);
// int main(){
//     int *p;
//     int data=3;
//     p=&data;
//     change(p);
//     cout<<data<<endl;
//     return 0;
// }
// int change(int *p){
//     *p=0;
//     return *p;
    
    
// }
// class printdata{
//     public:
//     void print(int i){
//         cout<<"int"<<i<<endl;
//     }
//     void print(float f){
//         cout<<"float"<<f<<endl;
//     }
//     void print(char* c){
//         cout<<"char"<<c<<endl;
//     }
// };
// int main(){
//     printdata p1;
//     p1.print(908);
//     p1.print("k");
// }
// int main(){
//     string s;
//     cout<<"Enter the string"<<endl;
//     getline(cin,s);
//     cout<<"This is initial string"<<endl;
//     cout<<s<<endl;
//     s.push_back('i');
// cout<<s<<endl;
// s.pop_back();
// cout<<s<<endl;
// }
// class cal{
//     private:
//     int x,y,res;
//     public:
//     void setData(int a,int b){
//         x=a;
//         y=b;
//     }
//     int mult()
// {
//     res=x*y;
//     return res;
// }
// int add(){
//     res=x+y;
//     return res;
// }
// };
// int main(){
//     int a,b;
//     cout<<"Enter the value of a &b";
//     cin>>a>>b;
//     cal c1;
//     c1.setData(a,b);
//    cout<<c1.mult()<<endl;
//     cout<<c1.add();
// }
// class ABC{
//     private:
//     int x,y;
//     public:
//     void setData(int a,int b)
//     {
//         x=a;
//         y=b;
//     }
//     void show(){
//         cout<<"x= "<<x<<endl;
//         cout<<"y= "<<y<<endl;
//     }
//     void change(ABC &ob2){
// ob2.x=ob2.x+50;
// ob2.y=ob2.y+20;
//     }
//     void happy(int x,int y);
// };
// void ABC::happy(int x,int y){
//     cout<<x+y;
// }
// int main(){
// //     int a,b;
// //     ABC ob1;
// //    cout<<"enter"<<endl;
// //    cin>>a>>b;
// //    ob1.setData(a,b);

// //     ob1.happy(a,b);
// // }
// // int num=90;
// // class Global{
// //     private:
// //     int num;
// //     public:
// //     void setData(int a){
// //         num=a;
// //     }
// //     void printdata();
// // };
// // void Global::printdata(){
// //     int num=45;
// //     cout<<num<<endl;
// //     cout<<::num<<endl;
// //     cout<<Global::num;
// // }
// // int main(){
 
// //     Global g;
// //     g.setData(20);
// //     g.printdata();

// // }
// class num{
//     private:
//     int num;
//     static int count;
//     public:
//     void input(int a){
//         num=a;
//         count++;
//     }
//     void show(){
//         cout<<num<<endl;
//         cout<<count<<endl;
//     }
// };
// int num::count=9;
// int main(){
//     num n1;
//     num n2;
//     num n3;
//     n3.input(10);
//     n2.input(30);
//     n1.input(80);
//     n1.show();
//     n2.show();
//     n3.show();
// }
// int main(){
//     string name[20];
//     int i;
//     cout<<"Enter the name"<<endl;
//     for(int i=0;i<20;i++){
//     cin>>name[i];}
//     for(i=0;name[i]!='\0';i++){
// if(name[i]==name[i+1]){
// continue;
// }
// else{
//     cout<<name[i];
// }
//     }
// }
// class Number{
//     public:
//     static int revdigit(int num){
//         int rem,rev=0;
//     while(num>0){
//         rem=num%10;
//         rev=(rev*10)+rem;
//         num=num/10;
//     }
//     return rev;
    
//     }
//     static void palindrome(int num){
//         int revnum;
//         revnum=revdigit(num);
//         if(num==revnum){
//             cout<<"Palindrome"<<endl;
//         }
//         else{
//             cout<<"Not a Palindrome"<<endl;
//         }
//     }
// };
// int main(){
//     int num;
//     cout<<"enter the num"<<endl;
//     cin>>num;
//     Number::palindrome(num);
// }

///***********************************
