#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int n;cin>>n;
    int ct = 0, sum = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ct++;
            sum += i;
            if(n/i!=i){
                sum+=n/i;
                ct++;
            }
        }
    }
    cout<<ct<<' '<<sum<<endl;
}