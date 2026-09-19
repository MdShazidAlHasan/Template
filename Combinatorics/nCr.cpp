#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6;
const int MOD = 1e9+7;
int fac[MAXN], infac[MAXN];

int expo(int a, int b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        int x = expo(a, b/2);
        return (x*x)%MOD;
    }else{
        int x = expo(a, b/2);
        int ans = (x*x)%MOD;
        return (ans*a)%MOD;
    }
}

int inverse(int a){
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
int nCr(int n, int r){
    if(n<0 or r<0 or r>n){
        return 0;
    }
    int num = fac[n];
    int den = (infac[r])*(infac[n-r])%MOD;
    return (num*den)%MOD;
}

signed main(){
    compute_factorials();
    int n, m;cin>>n>>m;
    cout<<nCr(m, n)<<endl;
}