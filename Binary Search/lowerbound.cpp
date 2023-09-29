#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;
int custom_lower_bound(vector<int>&v, int e){
    int lo = 0, hi = v.size()-1, mid;
    while(lo<hi){
        int mid = (lo+hi)/2;
        if(v[mid]<e){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    return lo;
}

int main(){
    vector<int>v = {1, 3 , 5, 7, 9};
    cout<<custom_lower_bound(v, 4);
}