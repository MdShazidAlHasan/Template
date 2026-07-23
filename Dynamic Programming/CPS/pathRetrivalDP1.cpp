#include <bits/stdc++.h>

using namespace std;
int n, x;
vector<int>v;
int dp[1000001];
int nxt[100001];
int goriberDP(int taka)
{   
    if(taka == 0)
    {
        return 0;
    }
    if(dp[taka] != -1)
    {
        return dp[taka];
    }
    int ans = 1e9;
    for(int coin: v)
    {
        if(taka >= coin)
        {
            int opResult = 1 + goriberDP(taka - coin);
            if(opResult < ans)
            {
                ans = opResult;
                nxt[taka] = taka-coin;
            }

        }
    }
    return dp[taka] = ans;
}

signed main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    memset(dp, -1, sizeof dp);
    cout << goriberDP(x) << endl;
    cout << "COINS: ";
    while(x != 0)
    {
        cout << x - nxt[x]<< ' ';
        x = nxt[x];
    }
}