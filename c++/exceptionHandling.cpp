// Errors:
// 1.Logical Error:Due to wrong logic in program
//Not identifiesd by program
//2.Semantic Error:Due to wrong syntax of code.
// identifiesd by program
//3.Runtime Error:Exception Handling
//Exception Handling are some upredictible circumstances whwn our program terminates suddenly with some erros
//Exception handling is the ability to hndle the program so that our program keep runnning

// syntax:
// try{"this block contains those code in which the code that can give error"}
// catch{"whenever the ex ception is found in try block it is thrown to catch() block and will handle the exception"}

// eg:
#include<iostream>
using namespace std;

// int main(){
// int a,b,c;
// cout<<"Enter the numbers";
// cin>>a>>b;
// try{
//     if(b!=0){
//         c=a/b;
//         cout<<a<<" divided by "<<b<<" is "<<c<<endl;
//     }
//     else{
//         throw(b);
//     }
// }
// catch(int b){
//     cout<<"You have divided by"<<b;
// }
// return 0;
// }

// Multiple Catch
// int main(){
// int num[]={10,20,30,40,50};
// double x,y,z;
// int index;
// cout<<"Enter two numbers";
// cin>>x>>y;
//     try{
//         if(y==0){
//             throw("Divison by 0 is not possible");
//         }
//         z=x/y;
//         cout<<"z is "<<z<<endl;
//         cout<<"Enter the Index number"<<endl;
//         cin>>index;
//         if(index<0||index>4){
//             throw index;
//         }
//         cout<<"Value is "<<num[index]<<endl;
//     }
// catch(const char*msg){
//     cerr<<msg<<endl;
// }
// catch(int n){
//     cerr<<"invalid INdex number "<<n<<endl;
// }
// return 0;
// }

//There is a special block called catch all catch(...) that can be used to catch all types of expression


// double calculation (double a ,double b){
//     if(b==0){
//         throw"Division by zero is not Possible";
//     }
//     return (a/b);
// }

// void showvalue(int num[],int index){
//     if(index<0||index>4){
//         throw index;
//     }
//     cout<<"VAlue is "<<num[index]<<endl;
// }

// int main(){
// double a,b,c;
// int index;
// int num[]={10,20,30,40,50};
// cout<<"Enter the values";
// cin>>a>>b;
// try{
//     c=calculation(a,b);
//     cout<<"Divison is "<<c<<endl;
//     cout<<"Enter the index"<<endl;
//     cin>>index;
//     showvalue(num,index);
// }
// catch(const char *msg){
// cerr<<msg<<endl;
// }
// catch(...){
//     cerr<<"Invalid Index Number"<<endl;
// }
// cout<<"End of Program"<<endl;
// return 0;
// }

//Re-throwing an Exception
//there is no need of passing argument if you want to rethrow  'throw;'

void divn(int x,int y){
    cout<<"Inside func()"<<endl;
    try{
        if(y==0){
            throw y;
        }
        else{
            cout<<"division :"<<x/y<<endl;
        }
    }
    catch(int a){
        cout<<"caught int inside func()"<<endl;
        throw;//rethrowing an exception
    }
}
int main(){
    cout<<"Inside main()"<<endl;
    try{
        divn(10,5);
        divn(10,0);
    }
    catch(int a){
        cout<<"caught int inside main()"<<endl;
    }
    cout<<"End of main()"<<endl;
}