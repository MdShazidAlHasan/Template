#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int k;cin>>k;
    int visited[n+1] = {0};
    int distance[n+1] = {0};
    queue<int>q;
    for(int i=0;i<k;i++){
        int fire;cin>>fire;
        q.push(fire);
        visited[fire] = 1;
    }
    int ans = 0;
    while(!q.empty()){
        int cr = q.front();
        q.pop();
        for(int cn:graph[cr]){
            if(visited[cn])continue;
            q.push(cn);
            visited[cn] = 1;
            distance[cn] = distance[cr] + 1;
            ans = max(ans, distance[cn]);
        }
    }
    cout<<ans<<endl;
}