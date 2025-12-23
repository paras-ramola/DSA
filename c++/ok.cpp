#include <iostream>
#include <string>
using namespace std;
int sum(int a, int b)
{
    int c;
    c = a + b;
    return c;
}
class Employee
{
public:
    string name;
    int salary;
    Employee(string name, int salary,int sp)
    {
        this->name = name;
        this->salary = salary;
        this->secret=sp;
    }
    void printdetails() // method
    {
        cout << "Employee No.1:" << this->name <<"Password:"<<this->secret<< endl;
    }

    private:
    int secret;
};
class Programmer:public Employee
{
    public:
    int errors;
};
    int main()
    {
        // cout<<"hello world"<<endl<<"really"<<endl;
        // cout<<"next line";

        // camelCase Notation
        //  int marksInMaths=83;
        //  float const score1=45.899447434;
        //  double score2=89.099284;
        //  long double score3=90.9084982;
        //  score1=99.08;
        //  cout<<"The marks of student in Maths is "<<score1<<endl;
        //  cout<<"The marks of student in Maths is "<<score2<<endl;
        //  cout<<"The marks of student in Maths is "<<score3<<endl;
        // int a,b;
        // cout<<"Enter First Number"<<endl;
        // cin>>a;
        // cout<<"Enter second Number"<<endl;
        // cin>>b;
        // cout<<"a + b is"<<a+b<<endl;
        // cout<<"a - b is"<<a-b<<endl;
        // cout<<"a * b is"<<a*b<<endl;
        // cout<<"a / b is"<<(float)a/b<<endl;

        // int age;
        // cout << "enter Your Age" << endl;
        // cin >> age;
        // switch (age)
        // {
        // case 12:
        //     cout << "you are 12 years old";
        //     break;
        // case 18:
        //     cout << "you are 18 years old";
        //     break;
        // case 70:
        //     cout << "you are 70 years old";
        //     break;
        // default:
        //     cout << "You are neither 12 nor 18";
        //     break;
        // }
        // if(age>150 || age<1){
        //     cout<<"Invalid Age!"<<endl;
        // }
        // else if(age>=18){
        //     cout<<"You Can Vote"<<endl;
        // }

        // else{
        //     cout<<"You Cannot Vote";
        // }

        // int index=0;
        //  while(index<34){
        //      cout<<"We are at Index:"<<index<<endl;
        //      index=index+1;
        //  }
        //  do{
        //      cout<<"We are at Index:"<<index<<endl;
        //    index=index+1;
        //  }
        //  while(index<2334);
        //   for (int  i = 0; i <34; i++)
        //   {
        //      cout<<"The Value of i is:"<<i<<endl;
        //   }

        // int a,b;
        // cout<<"Enter First Number"<<endl;
        // cin>>a;
        // cout<<"Enter second Number"<<endl;
        // cin>>b;
        // cout<<"The Sum of a & b is:"<<sum(a,b)<<endl;

        // int arr[3]={3,4,2};
        // cout<<arr[43];
        // int marks[6];
        // for(int i=0;i<6;i++){
        //     cout<<"Enter the Marks of"<<i<<"th student"<<endl;
        //     cin>>marks[i];
        // }
        // for(int i=0;i<6;i++){
        //     cout<<" Marks of"<<i<<"th student is"<<marks[i]<<endl;
        // }

        // int  arr2d[2][3]={
        //     {1,2,3},
        //     {4,5,6}
        // };
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<3;j++){
        //         cout<<arr2d[i][j]<<endl;
        //     }
        // }
        // int n,m;
        // cout<<"enter the num of rows"<<endl;
        // cin>>m;
        //  cout<<"enter the num of coloumn"<<endl;
        // cin>>n;
        // int arr[m][n];
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<"enter the element "<<i<<","<<j<<endl;
        //         cin>>arr[i][j];
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<"the  value at "<<i<<","<<j<<"is"<<arr[i][j]<<endl;

        //     }
        // }

        // int a=342;
        // float b=90.378;
        // cout<<(float)a/45<<endl;
        // cout<<(float)b;

        // string name="parry";
        // cout<<"the name is "<<name<<endl;
        //  cout<<"the name is "<<name.length()<<endl;
        //  cout<<"the name is "<<name.substr(2,5)<<endl;

        // int a=35;
        // int *ptr;
        // ptr=&a;
        // cout<<ptr<<endl;
        // cout<<*ptr<<endl;
        // cout<<&ptr<<endl;

        Employee par("paras constructor", 1000000,92309);
        // par.name="paras";
        // par.salary=1000000000;
        par.printdetails();
        

        
        // cout<<par.secret;
        // cout<<"Employee No.1:"<<par.name<<endl;

        return 0;
    }