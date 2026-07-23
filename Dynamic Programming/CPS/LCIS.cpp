#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int a[N], b[N];
int dp[N][N][N];

int LCIS(int i, int j, int last) {
    if (i > n || j > n) return 0;

    int &ans = dp[i][j][last];
    if (ans != -1) return ans;

    ans = 0;

    // Skip current element of a
    ans = max(ans, LCIS(i + 1, j, last));

    // Skip current element of b
    ans = max(ans, LCIS(i, j + 1, last));

    // Take both if possible
    if (a[i] == b[j] && (last == 0 || b[j] > b[last])) {
        ans = max(ans, 1 + LCIS(i + 1, j + 1, j));
    }

    return ans;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    memset(dp, -1, sizeof(dp));

    cout << LCIS(1, 1, 0) << '\n';
}