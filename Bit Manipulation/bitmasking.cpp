#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

//problem :  https://codeforces.com/blog/entry/73558


int main(){
    int n;cin>>n;
    vector<int>masks(n, 0);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int mask = 0;
        for(int j=0;i<x;j++){
            int day;cin>>day;
            mask = mask | (1<<day);
        }
        masks[i] = mask;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int intersection = (masks[i] | masks[j]);
            int common_days = __builtin_popcount(intersection);
            ans = max(ans, common_days);
        }
    }
    cout<<ans<<endl;
}