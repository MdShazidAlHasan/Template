#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
int subtree_sum[N], even_ct[N];

void dfs(int vertex, int parent){
    // Take action on vertex after entering the vertex 
    if(vertex%2==0){
        even_ct[vertex]++;
    }
    subtree_sum[vertex] += vertex; 
    for(auto child:graph[vertex]){
        // Take action on a child before entering the child node
        if(child==parent)continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child]; 
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
    for(int i=1;i<=n;i++){
        cout<<subtree_sum[i]<<' '<<even_ct[i]<<endl;
    }
}