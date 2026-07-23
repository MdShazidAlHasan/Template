#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int n, mx = 100000;
    cin >> n;
    vector<int> sum(mx + 5, 0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum[x] += x;
    }
    vector<int> dp(mx + 5, 0);
    dp[1] = sum[1];
    dp[2] = max(sum[1], sum[2]);
    for(int i = 3; i <= mx; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
    }
    // for(int i = 0; i < 4; i++)cout << dp[i] << endl;
    cout << dp[mx] << endl;
}