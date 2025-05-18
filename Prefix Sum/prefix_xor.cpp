#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x[n+1];

    int p[n+1];
    p[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> x[i];

        p[i] = p[i-1] ^ x[i];
    }

    for(int i = 1; i <= n; i++){
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}
