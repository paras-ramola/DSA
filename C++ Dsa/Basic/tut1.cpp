#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

//1. 1 1 1
 //  2 2 2
 //  3 3 3
    // int i=1;
    // while(i<=3){
    //     int j=1;
    //     while(j<=3){
    //         cout<<i;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

//2. 1 2 3 4 
//   1 2 3 4
//   1 2 3 4 
//   1 2 3 4
// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=n){
//         cout<<j;
//         j=j+1;
//     }
//     i=i+1;
//     cout<<endl;
// }

// 3.
// 654321
// 654321
// 654321

// int i=n;
// while(i>=1){
//     int j=n;
//     while(j>=1){
//         cout<<j;
//         j=j-1;
//     }
//     i=i-1;
//     cout<<endl;
// }

//4.
// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
// 13 14 15 16 

// int i=1;
// int count=1;
// while(i<=n){
//     int j=1;
//     while(j<=n){
//         cout<<count<<" ";
//         count++;
//         j++;
//     }
//     cout<<endl;
//     i++;
// }

//withou extra variable
// int i=1;
// while(i<=n*n){
//     printf("%d ", i);
//     if (i % n == 0){// checks if the current number printed is at the beginning of a new row.
//         printf("\n");
//     }
//     i++;
// }}

//5.
// *
// **
// ***
// ****

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=i){
//         cout<<"*";
//         j++;
//     }
//     i++;
//     cout<<endl;
// }

//6.
// 1
// 22
// 333
// 4444

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=i){
//         cout<<i;
//         j++;
//     }
//     i++;
//     cout<<endl;

// }

//7.
// 1
// 23
// 456
// 78910
// int i=1;
// int count=1;
// while(i<=n){
//     int j=1;
//     while(j<=i){
//         cout<<count++;//count=count+1
//         j++;
//     }
//     i++;
//     cout<<endl;
// }

// without variable_>Wrong
//  int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=i){
//         cout<<i+j-1;
//         j++;
//     }
//     i++;
//     cout<<endl;
// }


//8.
// 1
// 21
// 321
// 4321

// int i=1;
// while(i<=n){
//     int j=i;
//     while(j>=1){
//         cout<<j;
//         j--;
//     }
//     i++;
//     cout<<endl;
// }

//9.
// AAAAAAA
// BBBBBBB
// CCCCCCC
// DDDDDDD

// int i=1;
// while(i<=n){
// int j=1;
// while(j<=n){
//     char ch='A'+i-1;
//     cout<<ch;
//     j++;
// }
// cout<<endl;
// i++;
// }

//10.
// ABCD
// ABCD
// ABCD

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=n){
//         char ch='A'+j-1;
//         cout<<ch;
//         j++;
//     }
//     cout<<endl;
//     i++;
// }

// 11.
// ABCD
// EFGH
// IJKL
// MNOP

// int i=1;
// while(i<=n*n){
//     char ch='A'+i-1;
//     cout<<ch;
//     if(i%n==0){
//         cout<<endl;
//     }
//     i++;
// }

//12.
// ABC
// BCD
// CDE

// int i=1;
// while(i<=n){

//     int j=1;

//     while(j<=n){
//         char ch='A'+i+j-2;
//         cout<<ch;
//         ch++;
//         j++;
//     }
//     cout<<endl;
//     i++;
// }

//OR 

// int i=1;
// while(i<=n){
//     int j=1;
//     char ch='A'+i-1;
//     while(j<=n){
//         cout<<ch;
//         ch++;
//         j++;
//     }
//     i++;
//     cout<<endl;
// }



//13.
// A
// BB
// CCC
// DDDD

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=i){
//         char ch='A'+i-1;
//         cout<<ch;
//         j++;
//     }
//     i++;
//     cout<<endl;
// }

// 14.
// A
// BC
// CDE
// DEFG

// int i=1;
// while(i<=n){
// int j=1;
// while(j<=i){
//     char ch='A'+i+j-2;
//     cout<<ch;
//     j++;
// }
// cout<<endl;
// i++;
// }


 
// 15.
// A
// BC
// DEF
// GHIJ

//without third variable
// int i=1;
// char ch='A';
// while(i<=n){
//     int j=1;
//     while(j<=i){  
//         cout<<ch;
//         j++;
//         ch++;

//     }
//     cout<<endl;
//     i++;
// }


// 16.
// D
// CD
// BCD
// ABCD

// int i=1;
// int val=n;
// while(i<=n){
//     int j=1;
//     char ch='A'+n-i;
//     while(j<=i){
//         cout<<ch;
//         ch++;
//         j++;
//     }
//     cout<<endl;
//     i++;
// }

//17.i  
//    *
//   **
//  ***
// ****

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=n-i){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
//     while(k<=i){
//         cout<<"*";
//         k++;
//     }
//     cout<<endl;
//     i++;

// }

//18.
// ****
// ***
// **
// *

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=n-i+1){
//         cout<<"*";
//         j++;
//     }
//     cout<<endl;
//     i++;
// }


//19.
// ****
//  ***
//   **
//    *

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<i){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
//     while(k<=n-i+1){
//         cout<<"*";
//         k++;
//     }
//     i++;
//     cout<<endl;
// }


//20.
// 1111
//  222
//   33
//    4

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<i){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
//     while(k<=n-i+1){
//         cout<<i;
//         k++;
//     }
//     i++;
//     cout<<endl;
// }


//21.
//     1
//    22
//   333
//  4444

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<=n-i+1){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
//     while(k<=i){
//         cout<<i;
//         k++;
//     }
//     i++;
//     cout<<endl;
// }

//22.
// 1234
//  234
//   34
//    4

// int i=1;
// while(i<=n){
//     int j=1;
//     while(j<i){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
//     while(k<=n-i+1){
//         cout<<k+i-1;
//         k++;
//     }
//     i++;
//     cout<<endl;
// }


//23.
//     1
//    23
//   456
//  78910

// int i=1;
// int count=1;
// while(i<=n){
//     int j=1;
//     while(j<=n-i+1){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
//     while(k<=i){
//         cout<<count;
//         count++;
//         k++;
//     }
//     i++;
//     cout<<endl;
// }

//24.
//     1
//    121
//   12321
//  1234321

// int i=1;
// while(i<=n){
//     int j=1;
// //1st Trinagle(Space)
//     while(j<=n-i+1){
//         cout<<" ";
//         j++;
//     }
//     int k=1;
// //2nd Triangle
//     while(k<=i){
//         cout<<k;
//         k++;
//     }
// //3rd Triangle
//    int start=i-1;
//    while(start){
//     cout<<start;
//     start--;
//    }
//     i++;
//     cout<<endl;
// }



// 25.
int i=1;
while(i<=n){
int j=1;
while(j<=n-i+1){
    cout<<j;
    j++;
}
int k=1;
while(k<i){
    cout<<"*";
    k++;
}
int l=1;
while(l<i){
    cout<<"*";
    l++;
}
int start=n-i+1;
while(start){
    cout<<start;
    start--;
}
cout<<endl;
i++;
}









}