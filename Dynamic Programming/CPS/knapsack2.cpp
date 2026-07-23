// #include <bits/stdc++.h>
// #define int long long 
// #define all(x) x.begin(), x.end()

// using namespace std;

// int n, w;
// const int N = 105;
// int weights[N], value[N];
// int dp[N][100010];
// int inf = 1e14;
// int solve(int id, int val){
//     if(val==0)return 0;
//     if(id==n+1)return inf;
//     int w = inf;
//     if(dp[id][val]!=-1)return dp[id][val];
//     if(val>=value[id]){
//         w = weights[id] + solve(id+1, val-value[id]);
//     }
//     w = min(w, solve(id+1, val));
//     return dp[id][val] = w;
// }

// signed main(){
//     cin>>n>>w;
    
//     for(int i=1;i<=n;i++){
//         cin>>weights[i]>>value[i];
//     }
//     int ans = 0;
//     for(int i=0;i<N;i++){
//         for(int j=0;j<100005;j++){
//             dp[i][j] = -1;
//         }
//     }
//     for(int i=0;i<100005;i++){
//         int temp = solve(1, i);
//         if(temp<=w)ans = i;
//     }
//     cout<<ans<<endl;
// }



//using map 

#include <bits/stdc++.h>
#define int long long 
#define all(x) x.begin(), x.end()

using namespace std;

int n, w;
const int N = 105;
int weights[N], value[N];
map<pair<int, int>, int>dp;
int inf = 1e14;
int solve(int id, int weight){
    if(id == n + 1) return 0;

    pair<int,int> p = {id, weight};

    if(dp.find(p) != dp.end()) return dp[p];

    int val = 0;

    if(weight >= weights[id]){
        val = value[id] + solve(id + 1, weight - weights[id]);
    }

    val = max(val, solve(id + 1, weight));

    return dp[p] = val;
}

signed main(){
    cin>>n>>w;
    
    for(int i=1;i<=n;i++){
        cin>>weights[i]>>value[i];
    }
    
    cout<<solve(1, w)<<endl;
}
