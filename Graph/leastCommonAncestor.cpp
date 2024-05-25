#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
int parent[N];

void dfs(int vertex, int par){
    // Take action on vertex after entering the vertex 
    parent[vertex] = par;
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        if(child==par)continue;
        dfs(child, vertex);
        // Take action on a child after existing child node
    }
    // Take action on vertex before exiting the vertex
}

vector<int> path(int v){
    vector<int>ans;
    while(v != -1){
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1, v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, -1);
    int x, y;cin>>x>>y;
    vector<int>path_x = path(x);
    vector<int>path_y = path(y);
    int lca = -1;
    for(int i=0;i<min(path_x.size(), path_y.size());i++){
        if(path_x[i]==path_y[i]){
            lca = path_x[i];
        }else{
            break;
        }
    }
    cout<<lca<<endl;
    
}