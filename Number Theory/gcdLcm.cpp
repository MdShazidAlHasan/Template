#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

// gcd using euclid's method
int gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    return gcd(b, a%b);
}
int main(){
    cout<<gcd(18, 12)<<endl;
    cout<<12*18/(gcd(18, 12))<<endl;
    cout<<__gcd(12,18)<<endl;   
}