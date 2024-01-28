
#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

int main(){
    printBinary(9);
    int a = 9;
    int i = 3;
    if((a & (1<<i)) != 0){
        cout<<"set bit"<<endl;
    }else{
        cout<<"not set bit"<<endl;
    }
    //set n=1th bit 
    printBinary(a | (1<<1));

    // unset n=3th bit 
    printBinary(a&(~(1<<3)));

    // toggle a bit
    printBinary(a^(1<<2));
    printBinary(a^(1<<3));

    //count set bit
    int ct = 0;
    for(int i=31;i>=0;i--){
        if((a&(1<<i)) !=0){
            ct++;
        }
    }
    cout<<__builtin_popcount(14);
    
}