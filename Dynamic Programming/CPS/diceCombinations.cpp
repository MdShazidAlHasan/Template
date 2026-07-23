// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                ways[i] += (ways[i - j]);
                ways[i] %= mod;
            }
        }
    }
    cout << ways[n] << endl;
}