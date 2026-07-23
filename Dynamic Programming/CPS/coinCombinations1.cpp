// https://cses.fi/problemset/task/1635/

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;

    int coins[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    const int MOD = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;
}