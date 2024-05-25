#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
bool vis[N];


bool dfs(int vertex, int par){
    // Take action on vertex after entering the vertex 
    if(vis[vertex])return true;
    vis[vertex] = true;
    bool isLoopExists = false;
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        if(vis[vertex] and par == child)continue;
        isLoopExists |= dfs(child, vertex);

        // Take action on a child after existing child node
    }
    return isLoopExists;
    // Take action on vertex before exiting the vertex
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1, v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int flag = 0;
    for(int i=0;i<=n;i++){
        if(vis[i])continue;
        if(dfs(i, -1)){
            flag = 1;
            break;
        }
    }
    cout<<flag<<endl;
    
}