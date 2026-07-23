#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1; 
int a[N], b[N];
int dp[N][N];
int n;

int LCS(int i, int j){
    if(i > n or j > n){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    if(a[i] == b[j]){
        ans = max(ans, 1 + LCS(i + 1, j + 1));
    }
    ans = max(ans, LCS(i + 1, j));
    ans = max(ans, LCS(i, j + 1));

    return dp[i][j] = ans;
}

signed main(){

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    memset(dp, -1, sizeof dp);
    cout << LCS(1, 1) << endl;
}