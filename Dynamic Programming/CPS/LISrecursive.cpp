#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001];
int dp[1001][1001];


int LIS(int idx, int prev){
    if( idx == n)
        return 0; 
    if(dp[idx][prev] != -1)
        return dp[idx][prev];
    int ans = 0;
    ans = max(ans, LIS(idx + 1, prev));
    if(a[idx] > prev){
        ans = max(ans, 1 + LIS(idx + 1, a[idx]));
    }
    return dp[idx][prev] = ans;
}

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << LIS(0, 0) << endl;
}