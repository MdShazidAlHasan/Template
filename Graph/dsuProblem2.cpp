// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int parent[N];
int size[N];
multiset<int>ms;

void make(int v){
    parent[v] = v;
    size[v] = 1;
    ms.insert(1);
}

int find(int v){
    if(v==parent[v])return v;
    parent[v] = find(parent[v]);
    return parent[v];
}
void merge(int a, int b){
    ms.erase(ms.find(size[a]));
    ms.erase(ms.find(size[b]));
    ms.insert(size[a]+size[b]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a, b);
        }
        parent[b] = a;
        merge(a, b);
        size[a] += size[b];
    }

}

int main(){
    int n, k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    int mn = N, mx = 0;
    while(k--){
        int u, v;cin>>u>>v;
        Union(u, v);
        if(ms.size()==1){
            cout<<0<<endl;
            continue;
        }
        int mn = *(ms.begin());
        int mx = *(--ms.end());
        cout<<mx - mn<<endl;
    }
}