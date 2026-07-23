#include <bits/stdc++.h>

using namespace std;
int w[100], v[100], n;
int dp[101][1000001], nxt[101][1000001];

int goriberDP(int in, int rw)
{
    if(in == n)
    {
        return 0;
    }
    if(dp[in][rw] != -1)
    {
        return dp[in][rw];
    }
    int ans = 0;
    int op1 = goriberDP(in + 1, rw);
    if(op1 > ans){
        ans = op1;
        nxt[in][rw] = 0;
    }
    if(w[in] <= rw)
    {
        int op2 = v[in] + goriberDP(in + 1, rw - w[in]);
        if(op2 > ans){
            ans = op2;
            nxt[in][rw] = 1;
        }
    }
    return dp[in][rw] = ans;
}


signed main(){
    int W;
    cin >> n >> W;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << goriberDP(0, W) << endl;
    int i = 0;
    while(W != 0 and i < n){
        if(nxt[i][W]){
            cout << w[i] << ' ';
            W -= w[i];
        }
        i++;
    }
}