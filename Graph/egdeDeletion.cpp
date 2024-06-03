#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
int subtree_sum[N];
int val[N];
void dfs(int vertex, int par){
    // Take action on vertex after entering the vertex 
    subtree_sum[vertex] += val[vertex-1];
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        if(child == par)continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        // Take action on a child after existing child node
    }
    // Take action on vertex before exiting the vertex
}

int main(){
    long long mod = 1e9+7;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<m;i++){
        int v1, v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, -1);
    long long ans = 0;
    for(int i=2;i<=n;i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans, part1*1LL*part2)%mod;
    }
}