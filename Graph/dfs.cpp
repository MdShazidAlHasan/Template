#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex){
    // Take action on vertex after entering the vertex 
    if(vis[vertex])return ;
    vis[vertex] = true;
    cout<<vertex<<endl;
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        cout<<"Parent "<<vertex<<", child "<<child<<endl;
        dfs(child);
        // Take action on a child after existing child node
    }
    // Take action on vertex before exiting the vertex
}

int main(){
    int n, m;
    cin>>n>>m;
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        int v1, v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(3);
}