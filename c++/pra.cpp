//Friend Class
//palindrome
#include<iostream>
#include<string>

using namespace std;
// class palin{
//     private:
//     int num;
//     public:
//     void setData(int a){
//         num=a;
//     }
//     friend void palindrome(palin ob);
// };
// void palindrome(palin ob){
//     int n,rem,rev=0;
//     n=ob.num;
//     while(n>0){
//         rem=n%10;
//         rev=(rev*10)+rem;
//         n=n/10;
//     }
//     if(rev==ob.num){
//         printf("Palindrome\n");
//     }
//     else{
//         printf("Not Palindrome\n");
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter Num:"<<endl;
//     cin>>n;
//     palin ob;
//     ob.setData(n);
//     palindrome(ob);
// }

//swaping Two numbers
// class B;
// class A{
//     private:
//     int x;
//     public:
//     void setData(int a){
//         x=a;
//     }
//     void printData(){
//         cout<<"X:"<<x<<endl;
//     }
//     friend void swapValue(A &,B &);
// };
// class B{
//     private:
//     int y;
//     public:
//     void setData(int a){
//         y=a;
//     }
//     void printData(){
//         cout<<"Y:"<<y<<endl;
//     }
//     friend void swapValue(A &,B &);
// };
// void swapValue(A &ob1,B &ob2){
//     int temp;
//     temp=ob1.x;
//     ob1.x=ob2.y;
//     ob2.y=temp;
// }

// int main(){
//     A ob1;
//     B ob2;
//     int x,y;
//     cout<<"Enter Value of X:"<<endl;
//     cin>>x;
//     cout<<"Enter Value of Y:"<<endl;
//     cin>>y;
//     ob1.setData(x);
//     ob2.setData(y);
//     cout<<"====Before Swap===="<<endl;
//     ob1.printData();
//     ob2.printData();
//     cout<<"====After Swap====="<<endl;
//     swapValue(ob1,ob2);
//     ob1.printData();
//     ob2.printData();
// }

//friend Class
// class info{
//     private:
//     string name;
//     int rollno;
//     float sub1,sub2,sub3;
//     public:
//     void setData(){
//         cout<<"Enter Name:"<<endl;
//         getline(cin,name);
//         cout<<"Enter Roll.no"<<endl;
//         cin>>rollno;
//         cout<<"Enter marks in Hindi English & Maths:"<<endl;
//         cin>>sub1>>sub2>>sub3;
//     }
//     friend class Result;
// };
// class Result{
//     private:
// float total,per;
//     public:
//     void ResultVal(info ob){
//         total=ob.sub1+ob.sub2+ob.sub3;
//         per=(total*100)/300;
//         if(per>=35){
//             cout<<"Pass"<<endl;
//         }
//             else{
//                 cout<<"Work Harder.Success Lies in Learning from Mistakes."<<endl;
//             }
//         }
//     };


// int main(){
//     info ob;
//     ob.setData();
//     Result ob2;
//     ob2.ResultVal(ob);
// }


//swapping two numbers

// class B;
// class A{
//     private:
//     int x;
//     public:
//     void setData(int x){
//         this->x=x;
//     }
//     void printData(){
//         cout<<"X is :"<<x<<endl;
//     }
//     friend class Swap;
// };
// class B{
//     private:
//     int x;
//     public:
//     void setData(int x){
//         this->x=x;
//     }
//     void printData(){
//         cout<<"Y is :"<<x<<endl;
//     }
//     friend class Swap;
// };
// class Swap{
//     public:
//     void toSwap(A &ob1,B &ob2){
//         int temp;
//         temp=ob1.x;
//         ob1.x=ob2.x;
//         ob2.x=temp;
//     }
// };
// int main(){
// A ob1;
// B ob2;
// ob1.setData(2);
// ob2.setData(4);
// cout<<"====Before Swap===="<<endl;
// ob1.printData();
// ob2.printData();
// Swap s1;
// s1.toSwap(ob1,ob2);
// cout<<"====After Swap===="<<endl;
// ob1.printData();
// ob2.printData();
// }

//write a program which include both defalut and parameterized constructor....using atleast two variable  1)name as string & 2)age as pointer..Also make an another function called as sum of digits () which could calculate sum of digits of age

#include<iostream>
using namespace std;

class info{
    private:
    int *age;
    string name;

    public:
    info(){
        int a=90;
    name= "harry";
    *age=a;
    
    cout<<"name :"<<name<<endl;
    cout<<"age"<<age;
    cout<<"sum:"<<sumofDigits();
    }
    info(string s,int a){
        name=s;
        age= new int(a);//new operator
        cout<<"name :"<<name<<endl;
        cout<<"age :"<<*age<<endl;
    }
    int sumofDigits(){  
        int n=*age;
        int sum=0;
        while(n!=0){
            sum=sum+n%10;
           n=n/10;
        }
            return sum;
    }

};
int main(){
info info1;
    string s;
    int a;
    cout<<"enter name"<<endl;
    getline(cin,s);
   cout<<"Enter age"<<endl;
   cin>>a;
   info ob(s,a);
   cout<<ob.sumofDigits();
    
}