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

/*
There are N children and K toffees. 
K<N count the number of ways to distibute among N 
students such that each students get 1 toffee only -->
nCk,  %M, M = 10^9+7
N<10^6, K<N<10^6
Q<10^5
n!/((n-r!) * r!)

*/
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
        int den = (fact[n-k] * fact[k])%M;
        ans = (ans%M * binExpo(den, M-2, M)%M)%M;
        cout<<ans<<endl;

    }

}