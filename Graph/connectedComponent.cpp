#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
bool vis[N];
vector<vector<int>>cc;
vector<int>current_cc;

void dfs(int vertex){
    // Take action on vertex after entering the vertex 
    if(vis[vertex])return ;
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        dfs(child);
        // Take action on a child after existing child node
    }
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
    
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        cnt++;
    }
    cout<<cnt<<endl;
    
    for(auto c:cc){
        for(auto e:c){
            cout<<e<<' ';
        }
        cout<<endl;
    }
}