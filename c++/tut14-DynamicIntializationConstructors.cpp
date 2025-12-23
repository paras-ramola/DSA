// Dynamic Initialization of Objects Using Constructor
#include<iostream>
using namespace std;
class BankDeposit{
    int principal;
    int year;
    float intrest;
    float returnValue;
    public:
    BankDeposit(){}//blank constructor-we can directly use  objects of class bd1,bd2 in main
BankDeposit(int p,int y,float r);//intrest rate are in decimal->float
BankDeposit(int p,int y,int r);//intrest rate are in %->integer
void show();
};
BankDeposit::BankDeposit(int p,int y,float r){
    principal=p;
    year=y;
    intrest=r;
    returnValue=principal;
    for(int i=0;i<y;i++){
        returnValue=returnValue*(1+intrest);
    }
}
BankDeposit::BankDeposit(int p,int y,int r){
    principal=p;
    year=y;
    intrest=float(r)/100;
    returnValue=principal;
    for(int i=0;i<y;i++){
        returnValue=returnValue*(1+intrest);
    }
};
void BankDeposit::show(){
    cout<<"Principal Amount was"<<principal
    <<".Return Value after"<<year
    <<"years is"<<returnValue<<endl;
}

int main(){
   
    BankDeposit bd1,bd2,bd3;
    int p,y;
    float r;
    int R;
   cout<<"Enter the Pricipal,Years and rate:"<<endl;
   cin>>p>>y>>r;
    bd1=BankDeposit(p,y,r);
bd1.show();
   cout<<"Enter the Pricipal,Years and rate:"<<endl;
   cin>>p>>y>>R;
    bd2=BankDeposit(p,y,R);
bd2.show();
return 0;
}