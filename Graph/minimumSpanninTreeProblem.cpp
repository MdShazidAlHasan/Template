#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;

int parent[N];
int siz[N];

void make(int v){
    parent[v] = v;
    siz[v] = 1;
}

int find(int v){
    if(v==parent[v])return v;
    parent[v] = find(parent[v]);
    return parent[v];
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(siz[a]<siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += siz[b];
    }

}
int32_t main(){
    int n;
    cin>>n;
    vector<pair<int, int>>cities(n+1);
    for(int i=1;i<=n;i++){
        cin>>cities[i].first>>cities[i].second;
    }
    vector<int>cost(n+1), k(n+1);
    for(int i=1;i<=n;i++)cin>>cost[i];
    for(int i=1;i<=n;i++)cin>>k[i];

    for(int i=1;i<=n;i++)make(i);

    vector<pair<int, pair<int, int>>>edges;
    for(int i=1;i<=n;i++){
        edges.push_back({cost[i], {0, i}});
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dist = abs(cities[i].first-cities[j].first)+abs(cities[i].second-cities[j].second);
            long long c = dist*1LL*(k[i]+k[j]);
            edges.push_back({c, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    long long total_cost = 0;
    vector<int>generator;
    vector<pair<int, int>>connections;
    for(auto &edge:edges){
        long long wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)==find(v))continue;
        Union(u, v);
        total_cost += wt;
        if(u==0 or v==0){
            generator.push_back(max(u, v));
        }else{
            connections.push_back({u, v});
        }

    }
    cout<<total_cost<<endl;
    cout<<generator.size()<<endl;
    for(auto e:generator)cout<<e<<' ';
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto e:connections){
        cout<<e.first<<' '<<e.second<<endl;
    }
}