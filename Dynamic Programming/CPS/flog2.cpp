#include <bits/stdc++.h>
#define int long long 
#define all(x) x.begin(), x.end()

using namespace std;

signed main(){
    int n, k;cin>>n>>k;
    vector<int>stones(n+1);
    for(int i=1;i<=n;i++){
        cin>>stones[i];
    }   
    int inf = 1e9;
    vector<int>cost(n+1, inf);
    cost[1] = 0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++)
            if(i-j>=1)
                cost[i] = min(cost[i], cost[i-j] + abs(stones[i]-stones[i-j]));        
         
    }
    cout<<cost[n]<<endl;
}