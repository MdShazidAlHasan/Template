#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5;
int k, h[N];
int dp[N];

int func(int i){
    if(dp[i]!=-1)return dp[i];
    if(i==0)return 0; 
    int cost = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            cost = min(cost, func(i-j)+abs(h[i]-h[i-j]));
        }
    }
    return dp[i] = cost;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1)<<endl;

}