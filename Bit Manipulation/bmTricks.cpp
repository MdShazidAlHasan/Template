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
    int n = 15;
    if(n&1){
        cout<<"Odd"<<endl;
    }else{
        cout<<"Even"<<endl;
    }
    //multiply by two and divides by two
    cout<<(n<<1)<<endl;
    cout<<(n>> 1)<<endl;

    //uppercse to lowercase 
    char B = 'B';
    char b = B | ' ';
    cout<<b<<endl;

    //lowercase to uppercase
    char d = 'd';
    char D = (d & '_');
    cout<<D<<endl;

    printBinary(59);

    //unset last 4 bits
    int a = 59;
    int i = 2;
    int x = (a & (~((1<<(i+1))-1)));
    printBinary(x);
    // unset first 3 bits
    i = 3;
    int c = (a & ((1<<(i+1))-1));
    printBinary(c);

    // check if a number is power of two 
    if(n&(n-1)){
        cout<<"Power of two"<<endl;
    }else{
        cout<<"Not power of two"<<endl;
    }
}