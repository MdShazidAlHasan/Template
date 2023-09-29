#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int searchvalue;
    ll lo = 0, hi = LLONG_MAX,mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(mid==searchvalue){
            break;
        }else if(searchvalue>mid){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }   
    
}