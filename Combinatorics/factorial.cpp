#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6;
const int MOD = 1e9+7;
ll fac[MAXN];

void compute_factorials(){
    fac[0] = 1LL;
    for(int i=1;i<MAXN;i++){
        fac[i] = (fac[i-1]*i)%MOD;
    }
} 

int main(){
    compute_factorials();   
}