#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

// class Student{
//         public:
//     char name[90];
//     int *age;

//     Student(const char* n,int a){
//        strcpy(name,n);
//         age=new int;
//         *age=a;
//     }
// ~Student(){
//     delete age;
// }
// };

// int main(){
//   //satically allocating memory
//   Student s1("John",90);  
//   Student s2("Rohan",70);

//   //dynamically
//   Student* dynamics1=new Student("Oppi",24);  
//   Student* dynamics2=new Student("Param",34) ; 
//   delete dynamics1;
//   delete dynamics2;
// return 0;
// }

// class Bank{
//     public:
//     string bankName;
//     int customerId;
//     string name;
//     Bank(string bN,int c,string n){
//         bankName=bN;
//         customerId=c;
//         name=n;
//     }
//     virtual void display(){
//         cout<<"Bank Name "<<bankName<<endl;
//         cout<<"Customer Id."<<customerId<<endl;
//         cout<<"Name: "<<name<<endl;
//     }
// };

// class savingAccounts:public Bank{
//     public:
//     float rate;
//     float debitAmount;

//     savingAccounts(string bN,int c,string n,float r,float dA):Bank(bN,c,n){
//         rate=r;
//         debitAmount=dA;
//     }
    
//     void display(){
//         cout<<"Bank Name "<<bankName<<endl;
//         cout<<"Customer Id."<<customerId<<endl;
//         cout<<"Name: "<<name<<endl;
//         cout<<"rate"<<rate<<endl;
//         cout<<"Enter Amount"<<debitAmount<<endl;
//     }
// };
// class checkingAccounts:public Bank{
//     public:
//     float returnAmount;

//     checkingAccounts(string bN,int c,string n):Bank(bN,c,n){
//             returnAmount=90000;
//      }
//     void display(){
//         cout<<"Bank Name "<<bankName<<endl;
//         cout<<"Customer Id."<<customerId<<endl;
//         cout<<"Name: "<<name<<endl;
//         cout<<"return amount"<<returnAmount<<endl;
//     }
// };
// int main(){
//     string bank="hdfc";
//     int id=90;
//     string name="rahul";
//     float r=7.0;
//     float m=483928;

// Bank b1(bank,id,name);
// savingAccounts s1(bank,id,name,r,m);
// checkingAccounts c1(bank,id,name);
// // Bank *bank_pointer;
// // bank_pointer=&s1;
// // bank_pointer->display();
// // bank_pointer=&c1;
// // bank_pointer->display();
// s1.display();
// }

// class area{
//     protected:
//     string name;
//     public:
//     area(string s){
//         name=s;
//     }
//     void display(){
//         cout<<"Area of your shape"<<name<<endl;
//     }
// };
// class rectangle:public area{
//     protected:
//     int l,w;
//     public:
//     rectangle(string s,int len,int wid):area(s){
//         l=len;
//         w=wid;
//     }
//     void display(){
//         cout<<"Area of "<<name<<"is"<<l*w<<endl;
//     }
// };
// class square:public area{
//     protected:
//     int a;
//     public:
//     square(string s,int ar):area(s){
//         a=ar;
//     }
//     void display(){
//         cout<<"Area of "<<name<<"is"<<a*a<<endl;
//     }
// };

// int main(){
//     string s="rectangle";
//     int l=9;
//     int w=9;
//     rectangle r1(s,l,w);
//     r1.display();
// }

int main(){
ofstream hout("sample.txt");

//creating a name string
string name;
cout<<"Enter your Name"<<endl;
// cin>>name;
for(int i=0;i<5;i++){
getline(cin,name);
hout<<name;
hout<<"\n";}

//writing a string to a file
hout<<"My name is "+ name<<endl;

hout.close();

ifstream hin("sample.txt");
string content;


int lineCount=0,wordCount=0,charCount=0;
while(getline(hin,content)){
    lineCount++;
    charCount+=content.length();
}
hin.close();
ofstream resultFile("result.txt");
resultFile<<"Number of lines"<<lineCount<<endl;
resultFile<<"Number of char"<<charCount<<endl;
}