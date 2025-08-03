#include <iostream>
#include<unordered_map>
#include<map>
using namespace std;

// void push(int arr[], int &n, int num) {
//     int idx = 0;

//     // Find the correct position to insert
//     while (idx < n && arr[idx] < num) {
//         idx++;
//     }

//     // Shift elements to the right
//     for (int i = n; i > idx; i--) {
//         arr[i] = arr[i - 1];
//     }

//     // Insert num at the correct index
//     arr[idx] = num;

//     // Increase the size
//     n++;

//     // Print the array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main() {
    unordered_map<string,int> mp;
    mp.insert(make_pair("hello",1));

    mp["param"]=8;

    // cout<<mp["param"];

    // mp["param"]=5;

    // cout<<mp["param"];



    cout<<mp["abc"];
    cout<<mp.at("param")<<endl;


    cout<<mp.count("abc");

    unordered_map<char,int>m;
    m['a']=9;   
    m['b']=8;   
    m['d']=0;   
    
    unordered_map<char,int> :: iterator it=m.begin();

    while(it!=m.end()){
        cout<<it->first<< " : "<<it->second<<endl;
        it++;

    }

   
}
