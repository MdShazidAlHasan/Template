#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int N, R;cin>>N>>R;
    // 2D vector
    vector<vector<int>>ans(N+1, vector<int>(R+1));   
    for(int n=1;n<=N;n++){
        for(int r=0;r<=R;r++){
            if(n==1){
                ans[n][r] = 1; //Base Case
            }else{
                ans[n][r] = 0;
                for(int j=0;j<=r;j++){
                    ans[n][r] += ans[n-1][j];
                }
            }
        }
    }
    cout<<ans[N][R]<<endl;
}