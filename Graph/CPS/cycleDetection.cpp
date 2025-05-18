#include <bits/stdc++.h>

using namespace std;
#define N 200005

int n, m;
vector<int>adj[N];
int previous_node[N];
int visited[N];
bool cycle_found = false;
int cycle_start, cycle_end;

void dfs(int u, int prev){
    if(visited[u]){
        if(cycle_found==false){
            cycle_found = true;
            cycle_start = u;
            cycle_end = prev;
        }
        return ;
    }
    visited[u] = 1;
    previous_node[u] = prev;
    for(int v:adj[u]){
        if(prev!=v)
            dfs(v, u);
    }
}


int main(){
    cin >> n >> m;
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i, 0);
    }
 
    if(cycle_found){
        cout << "Cycle detected\n";
 
        vector<int> path;
        int node = cycle_end;
        while(1){
            path.push_back(node);
            node = previous_node[node];
            if(node==cycle_start) break;
        }
        path.push_back(cycle_start);
 
        reverse(path.begin(), path.end());
 
        for(int node: path){
            cout << node << " -> ";
        }
        cout << endl;
    }
 
}