#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int n;cin>>n;
    vector<int>prime_factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }   
    if(n>1){
        prime_factors.push_back(n);
    }
    for(auto a:prime_factors)cout<<a<<' ';
}