#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

#define N 200010

vector<int>adj[N];
int visited[N];
int color[N];
int is_possible = 1;
void dfs(int u, int c){
    if(visited[u]){
        if(color[u]==c){
            return ;
        }else{
            is_possible = 0;
            return ;
        }
    }
    visited[u] = 1;
    color[u] = c;
    for(int v:adj[u]){
        dfs(v, 3-c);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    } 
    for(int i=1;i<=n;i++){
        if(!visited[i])dfs(i, 1);
    }
    if(!is_possible){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int i=1;i<=n;i++){
            cout<<color[i]<<' ';
        }
        cout<<endl;
    }
} 