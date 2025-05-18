#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

#define N 100000

vector<int>adj[N];
int level[N];
void dfs(int u, int par){
    for(int v:adj[u]){
        if(v==par)continue;
        level[v] = level[u] + 1;
        dfs(v, u);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    } 
    dfs(1, -1);
    for(int i=1;i<=n;i++){
        cout<<"Level of "<<i<<" is "<<level[i]<<endl;
    }

}