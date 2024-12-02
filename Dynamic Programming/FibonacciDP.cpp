#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;


int dp[1000];

// recursive TOP-DOWN
int fib(int n){
    if(dp[n]!=-1)return dp[n];
    if(n==0)return 0;
    if(n==1)return 1;
    return dp[n] = fib(n-1)+fib(n-2);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;cin>>n;
    // for(int i=0;i<=n;i++)
    //     cout<<fib(i)<<endl;

    // BOTTOM-UP
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl; 
}