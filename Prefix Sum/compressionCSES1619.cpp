

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>>v;
    set<int>st;
    for(int i=1;i<=n;i++){
        int l, r;cin>>l>>r;
        v.push_back({l, r});
        st.insert(l);
        st.insert(r);
    }
    map<int, int>mp;
    int cnt = 0;
    for(auto e:st){
        mp[e] = cnt++;
    }
    for(int i=0;i<n;i++){
        v[i].first = mp[v[i].first];
        v[i].second = mp[v[i].second];
    }
    int arr[2*n+5] = {0};
    for(auto e:v){
        arr[e.first]++;
        arr[e.second]--;
    }
    int mx = 0;
    for(int i=1;i<=2*n;i++){
        arr[i] += arr[i-1];
        mx = max(mx, arr[i]);
    }
    cout<<mx<<endl;
}