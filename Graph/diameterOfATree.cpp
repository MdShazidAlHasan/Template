#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
int depth[N], height[N];

void dfs(int vertex, int parent){
    // Take action on vertex after entering the vertex 
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        if(child==parent)continue;
        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
        // Take action on a child after existing child node
    }
    // Take action on vertex before exiting the vertex
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
    int mx = -1;
    int mx_node = -1;
    for(int i=1;i<=n;i++){
        if(depth[i]>mx){
            mx = depth[i];
            mx_node = i;
        }
        depth[i] = 0;
    }
    dfs(mx_node, -1);
    mx = -1;
    mx_node = -1;
    for(int i=1;i<=n;i++){
        if(depth[i]>mx){
            mx = depth[i];
            mx_node = i;
        }
    }
    cout<<mx<<endl;
}