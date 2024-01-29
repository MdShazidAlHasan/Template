#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   
    int subset_ct = (1<<n);
    for(int i=0;i<subset_ct;i++){
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0){
                cout<<v[j]<<' ';
            }
        }
        cout<<endl;
    }
}