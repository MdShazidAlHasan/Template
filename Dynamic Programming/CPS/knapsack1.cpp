#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

signed main()
{
    int n, w;
    cin >> n >> w;
    int weights[n + 1], value[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i] >> value[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (weights[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + value[i]);
            }
        }
    }
    cout << dp[n][w] << endl;
}