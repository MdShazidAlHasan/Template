#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

#define N 100000

vector<pair<int, int>>adj[N];
int preXor[N];

void dfs(int u, int par){
    for(auto child:adj[u]){
        int v = child.first;
        int w = child.second;
        if(v==par)continue;
        preXor[v] = preXor[u]^w;
        dfs(v, u);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    } 
    dfs(1, -1);
    // xor between 3 and 5;
    cout<<(preXor[1] ^ preXor[4])<<endl;

}