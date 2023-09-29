#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    vector<int>v;
    int searchVal;
    ll lo = 0, hi = v.size()-1, mid;
    ll result = 0;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(v[mid]<=searchVal){
            lo = mid+1;
            result = mid;
        }else{
            hi = mid-1;
        }
    }  
    cout<<result<<endl; 
}