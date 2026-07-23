// https://cses.fi/problemset/task/1635/

#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

int dp[101][1000001];

signed main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    const int inf = 1e9;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    int mod = 1e9 + 7;
    for (int c : coins)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - c >= 0)
            {
                dp[j] = (dp[j] + dp[j - c]) % mod;
            }
        }
    }

    if (dp[x] >= inf)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}