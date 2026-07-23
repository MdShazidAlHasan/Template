// https://cses.fi/problemset/task/1634/

#include <bits/stdc++.h>
#define int long long 
#define all(x) x.begin(), x.end()

using namespace std;

int dp[101][1000001];

signed main(){
    int n, x; cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    const int inf = 1e9;
    vector<int> dp(x+1, inf);
    dp[0] = 0;

    for(int c : coins){
        for(int j = c; j <= x; j++){
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }

    if(dp[x] >= inf) cout << -1 << endl;
    else cout << dp[x] << endl;
}