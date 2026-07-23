#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
string s;

bool isPal(int i, int j) {
    if (i >= j)
        return true;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != s[j])
        return dp[i][j] = false;

    return dp[i][j] = isPal(i + 1, j - 1);
}

int main() {
    memset(dp, -1, sizeof(dp));

    int q;
    cin >> q >> s;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << (isPal(l, r) ? "YES" : "NO") << '\n';
    }
} 