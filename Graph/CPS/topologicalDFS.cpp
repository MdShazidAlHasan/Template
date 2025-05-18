#include <bits/stdc++.h>

using namespace std;
#define N 2000005

vector<int>adj[N];
int visited[N];
vector<int>topological_order;

void dfs(int u){
    visited[u] = 1;
    for(int v:adj[u]){
        if(visited[v])continue;
        dfs(v);
    }
    topological_order.push_back(u);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i])dfs(i);
    }
    reverse(topological_order.begin(), topological_order.end());
    for(int node:topological_order){
        cout<<node<<' ';
    }
