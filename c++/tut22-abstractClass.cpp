
// Abstract Base Class
//ek class jo bnyi hi isliye jati h tki usse bki ki class derived ho ske
//iska use objects bnnane k liye nhi ho skta
//pure virtual function abstract class ko bnane m help krta h 
//abstract class m km se km ek pure virtual func hota h
// Eg:class Youtube

//Pure Virtual Function
// vo function jise derived class m define krna hi krna hota h vrna code error deta h
//syntax:func_Name()=0;
//Eg:below code m error ayega kyunki display ek pure virtual func h ,aur vo text class m defined nhi h

#include<iostream>
using namespace std;

class Youtube
{
protected:
    string title;
    float rating;
public:
    Youtube(string s,float r){
        title=s;
        rating=r;
    }
    virtual void display()=0;//do-nothing function-->PURE VIRTUAL FUNCTON
};

class ytVideo:public Youtube{
    float videolength;
    public:
    ytVideo(string s,float r,float vl):Youtube(s,r){
        videolength=vl;
    }
    void display(){
        cout<<"Title:"<<title<<endl;
        cout<<"Rating:"<<rating<<endl;
        cout<<"Duration"<<videolength<<"minutes"<<endl;
    }
};
class ytText:public Youtube{
    int words;
    public:
    ytText(string s,float r,int w):Youtube(s,r){
        words=w;
    }
    // void display(){
    //     cout<<"Title:"<<title<<endl;
    //     cout<<"Rating:"<<rating<<endl;
    //     cout<<"Text Length"<<words<<"words"<<endl;
    // }
};


int main(){
    string title;
    float rating,vlen;
    int wrd;

// for ytVideo
    title="Virtual Functions in C++";
    rating=4.78;
    vlen=7.9;
    ytVideo v1(title,rating,vlen);
    // v1.display();

//For ytText
    title="Virtual Functions in C++";
    rating=4.88;
    wrd=897;
    ytText t1(title,rating,wrd);
    // t1.display();

Youtube *yt[2];
yt[0]=&v1;
yt[1]=&t1;
   
yt[0]->display();   
yt[1]->display();   
}