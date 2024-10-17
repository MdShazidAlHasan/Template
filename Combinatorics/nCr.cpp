#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6;
const int MOD = 1e9+7;
ll fac[MAXN], infac[MAXN];

ll expo(ll a, ll b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ll x = expo(a, b/2);
        return (x*x)%MOD;
    }else{
        ll x = expo(a, b/2);
        ll ans = (x*x)%MOD;
        return (ans*a)%MOD;
    }
}

ll inverse(ll a){
    return expo(a, MOD-2);
}

void compute_factorials(){
    fac[0] = 1;
    infac[0] = 1;
    for(int i=1;i<MAXN;i++){
        fac[i] = (fac[i-1]*i)%MOD;
        infac[i] = inverse(fac[i]);
    }
} 

// nCr = n! / r! * (n - r)!
ll nCr(ll n, ll r){
    if(n<0 or r<0 or r>n){
        return 0;
    }
    ll num = fac[n];
    ll den = (infac[r])*(infac[n-r])%MOD;
    return (num*den)%MOD;
}

int main(){
    compute_factorials();
    int n, m;cin>>n>>m;
    cout<<nCr(m, n)<<endl;
}