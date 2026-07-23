#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001];
int dp[1001];


int LIS(int idx){
    if( idx == n)
        return 1; 
    if(dp[idx] != -1)
        return dp[idx];
    int ans = 0;
    for(int i = idx + 1; i <= n; i++){
        if(a[i] > a[idx]){
            ans = max(ans, 1 + LIS(i));
        }
    }
    return dp[idx] = ans;
}

signed main(){
    cin >> n;
    a[0] = INT_MIN;   
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << LIS(0) - 1 << endl;
}