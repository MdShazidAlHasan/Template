#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int p[n+2];
        p[0] = 0;
        for(int i=1;i<=n;i++){
            char x;cin>>x;
            p[i] = p[i-1] + x-'0';
        }
        map<int, int>mp;
        ll ans = 0;
        for(int i=0;i<=n;i++){
            int dif = p[i] - i;
            ans += mp[dif];
            mp[dif]++;
        }
        cout<<ans<<endl;
    }
}