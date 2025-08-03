//Binary & Decimal
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=0;
    int ans=0;
//Binary to Decimal
    // while(n!=0){
    //     int bits=n&1;
    //     ans=(bits*pow(10,i))+ans;
    //     n=n>>1;
    //     i++;
    // }

//Decimal to Binary
    while(n!=0){
        int digit=n%10;

        if(digit==1){
            ans=ans+pow(2,i);
        }
        
        n=n/10;
        i++;
    }

    cout<<ans<<endl;
}