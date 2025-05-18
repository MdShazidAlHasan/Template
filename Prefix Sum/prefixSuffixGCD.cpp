#include <bits/stdc++.h>
using namespace std;

#define ll long long

// problem: https://atcoder.jp/contests/abc125/tasks/abc125_c
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x[n+2];

    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }

    int prefix_gcd[n+2];
    prefix_gcd[0] = 0;

    for(int i = 1; i <= n; i++){
        prefix_gcd[i] = __gcd(prefix_gcd[i-1], x[i]);
    }

    int suffix_gcd[n+2];
    suffix_gcd[n+1] = 0;

    for(int i = n; i >= 1; i--){
        suffix_gcd[i] = __gcd(suffix_gcd[i+1], x[i]);
    }

    int mx = 0;

    for(int i = 1; i <= n; i++){
        mx = max(mx, __gcd(prefix_gcd[i-1], suffix_gcd[i+1]));
    }

    cout << mx << endl;

    return 0;
}