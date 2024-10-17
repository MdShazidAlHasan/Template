#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

const int MAXN = 1000;
ll ans[MAXN];
const int mod = 1e9+7;
int main(){
    ans[0] = 1;
    for(int i=1;i<=MAXN;i++){
        for(int j=0;j<=i-1;j++){
            ans[i] += (ans[j]*ans[i-1-j])%mod;
        }
    }
}