#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
string s;

int isPal(int i, int j) {
    if (i > j)
        return 0;
    if(i == j)return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if(s[i] == s[j]){
        ans = max(ans, 2 + isPal(i + 1, j - 1));
    }
    ans = max(ans, isPal(i + 1, j));
    ans = max(ans, isPal(i, j - 1));

    return dp[i][j] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> s;

    cout << isPal(0, n - 1) << endl;
} 