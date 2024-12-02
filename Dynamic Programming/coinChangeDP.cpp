#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;
const int N = 1e5;
int dp[N];

int func(int amount, vector<int>&coins){
    if(amount==0)return 0;
    if(dp[amount]!=-1)return dp[amount];
    int cost = INT_MAX;
    for(int coin : coins){
        if(amount-coin>=0)
            cost = min(cost, func(amount-coin, coins)+1);
    }
    return dp[amount] = cost;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n, amount;cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int ans = func(amount, coins);
    if(ans==INT_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
}