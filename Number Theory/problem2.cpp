#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e5 + 10;
int arr[N];

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr[x]++;        
    }
    map<int , int>m;
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            m[i]+=arr[j];
        }
    }
    int q;cin>>q;
    while(q--){
        int p, k;cin>>p>>k;
        ll lcm = p*1LL*k / __gcd(p, k);
        ll ans = m[p]+m[k];
        if(lcm<=N){
            ans -= m[lcm];
        }
        cout<<ans<<endl;
    }   
}