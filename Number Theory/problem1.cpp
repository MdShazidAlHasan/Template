//https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/
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


const int N = 1e6 +10;
int fact[N];
const int M = 1e9+7;
int main(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]* 1LL * i)%M;
    }
    int q;cin>>q;
    while(q--){
        int n, k;cin>>n>>k;
        int ans = fact[n];
        ans = (ans *1LL * fact[k])%M;
        int den = (fact[k-n] *1LL* fact[n])%M;
        ans = (ans* 1LL* binExpo(den, M-2, M))%M;
        cout<<ans<<endl;
    }

}