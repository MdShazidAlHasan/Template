#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5;
int h[N];
int dp[N];

int func(int i){
    if(dp[i]!=-1)return dp[i];
    if(i==0)return 0; 
    int cost = INT_MAX;
    // way 1 
    cost = min(cost, func(i-1) + abs(h[i]-h[i-1]));

    // way 2
    if(i>1)
        cost = min(cost, func(i-2)+abs(h[i]-h[i-2]));
    return dp[i] = cost;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1)<<endl;

}