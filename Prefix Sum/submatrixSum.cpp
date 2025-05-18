#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int x[n+1][m+1];

    memset(x, 0, sizeof x);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int v;
            cin >> v;

            x[i][j] = x[i-1][j] + x[i][j-1] - x[i-1][j-1] + v;

            cout << x[i][j] << " ";
        }
        cout << '\n';
    }

    cout.flush();

    while(1){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int sum = x[r2][c2] - x[r1-1][c2] - x[r2][c1-1] + x[r1-1][c1-1];

        cout << sum << endl;
    }

    return 0;
}