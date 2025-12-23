#include<iostream>
using namespace std;
#include<string.h>

//// eg1
// int sum(int a,int b){
//     cout<<"Using function with 2 arguments"<<endl;
//     return a+b;
// }
// int sum(int a,int b,int c){
//     cout<<"Using function with 3 arguments"<<endl;
//     return a+b+c;
// }
// string sum(string a ,string b){
//     return a+b;
// }
// int main(){
// cout<<"The sum of 3 and 5 is : "<<sum(3,5)<<endl;
// cout<<"The sum of 3,2 and 5 is : "<<sum(3,2,5)<<endl;
// cout<<"The sum of two strings is : "<<sum("Hello ,","World")<<endl;
// return 0;
// }

////eg2:Volume of different shapes

//volume of a cylinder
int volume(double r,int h){
    return (3.14*r*r*h);
}

// volume of a cube
int volume(int a){
    return (a*a*a);
}

//rectangular box
int volume(int l,int b,int h){
    return (l*b*h);
}

int main(){
    cout<<"Volume of a Cylinder is:"<<volume(5,9)<<endl;
    cout<<"Volume of a Cube is:"<<volume(4)<<endl;
    cout<<"Volume of a Cubiod is:"<<volume(6,3,3)<<endl;
}