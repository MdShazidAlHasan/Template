// https://cp-algorithms.com/graph/01_bfs.html

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int inf = 1e9;
vector<pair<int, int>> graph[N];
vector<int>level(N, inf);
int n, m;

int bfs(){
    deque<int>q;
    q.push_back(1);
    level[1] = 0;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop_front();
        for(auto child: graph[cur_v]){
            int child_v = child.first;
            int wt = child.second;

            if(level[cur_v] + wt < level[child_v]){
                level[child_v] = level[cur_v] + wt;
                if(wt==1)q.push_back(child_v);
                else q.push_front(child_v);
            }
        }
    }
    return level[n]!=inf?level[n]:-1;
}



int main(){
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1, v2;cin>>v1>>v2;
        if(v1 == v2)continue;
        graph[v1].push_back({v2, 0});
        graph[v2].push_back({v1, 1});
    }
    cout<<bfs();
}