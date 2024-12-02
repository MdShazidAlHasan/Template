#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;
int dp[310][10010];
int func(int index, int amount, vector<int>&coins){
    if(amount==0)return 1;
    if(index<0)return 0;
    if(dp[index][amount]!=-1)return dp[index][amount];
    int ways = 0;
    for(int coinAmont = 0;coinAmont<=amount;coinAmont+= coins[index]){
        ways += func(index-1, amount-coinAmont, coins);
    }
    return dp[index][amount] = ways;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n, amount;cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<func(n-1, amount, coins)<<endl;
}