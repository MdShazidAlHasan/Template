#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int binExpRecur(int a, int b){
    if(b==0)return 1;
    long long res = binExpRecur(a, b/2);
    if(b&1){
        return a*res*res;
    }else{
        return res*res;
    }
}

int binExpIter(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a *=a;
        b>>=1;
    }
    return ans;
}

int main(){
    int a = 2, b = 10;
    cout<<binExpRecur(a, b)<<endl;   
    cout<<binExpIter(2, 5)<<endl;
}