#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int binExpo(int a, int b, int m){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*1LL*a)%m;
        }
        a = (a*1LL*a)%m;
        b>>=1;
    }
    return ans;
}

int main(){
    int m = 31;
    cout<<binExpo(40, binExpo(50, 60, m-1), m)<<endl;    
}