#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;
double esp = 1e-5;
int main(){
    int n;cin>>n;
    double lo = 1, hi = n, mid;
    while(hi-lo>esp){
        mid = (hi+lo)/2;
        if(mid*mid<n){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout<<lo<<endl;
}