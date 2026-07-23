#include <bits/stdc++.h>
#define int long long 
#define all(x) x.begin(), x.end()

using namespace std;

signed main(){
    int n;cin>>n;
    vector<int>stones(n+1);
    for(int i=1;i<=n;i++){
        cin>>stones[i];
    }   
    int inf = 1e9;
    vector<int>cost(n+1, inf);
    cost[1] = 0;
    for(int i=2;i<=n;i++){
        cost[i] = min(cost[i], cost[i-1] + abs(stones[i]-stones[i-1]));        
        if(i>2)cost[i] = min(cost[i], cost[i-2] + abs(stones[i]-stones[i-2])); 
    }
    cout<<cost[n]<<endl;
}