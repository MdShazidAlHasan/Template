#include <bits/stdc++.h>

using namespace std;

#define ll long long


// Kadane's algorithm to find the maximum
// subarray sum but we are using the prefix sum array here.
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll pre_sum[n+1];
    pre_sum[0] = 0;
    for(int i=1;i<=n;i++){
        pre_sum[i] = pre_sum[i-1] + a[i];
    }
    ll max_sum = INT_MIN;
    ll min_idx = 0;
    for(int i=0;i<=n;i++){
        if(pre_sum[i] < pre_sum[min_idx]){
            min_idx = i;
        }
        max_sum = max(max_sum, pre_sum[i] - pre_sum[min_idx]);
    }
    cout<<max_sum<<endl;
}