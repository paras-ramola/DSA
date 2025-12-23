#include<iostream>
#include<math.h>
using namespace std;

class Point{
    int x,y;
    public:
    Point(int a,int b){
        x=a;
        y=b;
    }
       friend int distance(Point o1,Point o2);
};


int  distance(Point o1,Point o2){
  return sqrt(pow(o2.x-o1.x,2)+pow(o2.y-o1.y,2)*1.0);
}

int main(){
Point p1(-3,3);
Point p2(3,5);
float res=distance(p1,p2);
cout<<res<<endl;
return 0;
}