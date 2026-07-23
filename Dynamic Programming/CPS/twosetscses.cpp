// https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>
#define int long long 
#define all(x) x.begin(), x.end()

using namespace std;

int n;
int dp[501][62626];
const int mod = 1e9 + 7;

int fun(int idx, int sum){
    if(sum * 2 > (n + 1) * n / 2) return 0;
    if(idx > n){
        if(sum * 2 == (n + 1) * n / 2){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    int ans = 0;
    ans += fun(idx + 1, sum + idx) % mod;
    ans %= mod;
    ans += fun(idx + 1, sum) % mod;

    return dp[idx][sum] = ans % mod;
}


signed main(){
    cin >> n;
    memset(dp, -1, sizeof dp);
    const int inv2 = 500000004;
    cout << fun(1, 0) * inv2 % mod << '\n';
}