#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    // ofstream out;
    // out.open("sample.txt");
    // out<<"This is FileIo";
    // out.close();
    ifstream in;
    string st;
    in.open("sample.txt");
//1.
    // in>>st;
    // cout<<st;
//2.
while(in.eof()==0){
    getline(in,st);
    cout<<st<<endl;
}
    in.close();
    return 0;
}