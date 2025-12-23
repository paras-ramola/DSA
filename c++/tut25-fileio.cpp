#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // string st="Hello World";
    string st2;
    // //opening file using constructor and writing it
    // ofstream out("sample.txt");
    // out<<st;

//     //openinf file using constructor and reading it
    ifstream in("sample.txt");
    getline(in,st2);//or in>>st(for single char)//reading 
    cout<<st2;//printing it
return 0;
}

// eg:
// int main(){
// ofstream hout("sample.txt");

// //creating a name string
// string name;
// cout<<"Enter your Name"<<endl;
// // cin>>name;
// getline(cin,name);
// hout<<name;

// //writing a string to a file
// hout<<"My name is "+ name<<endl;

// hout.close();

// ifstream hin("sample.txt");
// string content;
// getline(hin,content);
// cout<<content;

// hin.close();
// }