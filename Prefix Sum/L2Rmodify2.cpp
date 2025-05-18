#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n, q;
    cin>>n>>q;
    int a[n+2] = {0};

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i] += x;
        a[i+1] -= x;
    }
    
    cout<<endl;
    while (q--){
        int l, r, x;
        cin>>l>>r>>x;
        a[l] += x;
        a[r+1] -= x;
    }
    for(int i=1;i<=n;i++){
        a[i] += a[i-1];
        cout<<a[i]<<" ";
    }
    
    
}