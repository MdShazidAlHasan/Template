#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n, q;
    cin>>n>>q;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll pre_sum[n+1];
    pre_sum[0] = 0;
    for(int i=1;i<=n;i++){
        pre_sum[i] = pre_sum[i-1] + a[i];
    }
    while (q--){
        int l, r;
        cin>>l>>r;
        cout<<pre_sum[r] - pre_sum[l-1]<<endl;
    }
    
}