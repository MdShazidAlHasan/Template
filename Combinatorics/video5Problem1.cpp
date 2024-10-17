#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int N,M;cin>>N>>M;
    vector<vector<ll>>A(N+1, vector<ll>(M+1, 0));
    for(int n=1;n<=N;n++){
        for(int m=1;m<=M;m++){
            if(n==1){
                A[n][m] = m;
            }else{
                for(int i = 1;i<=m-1;i++){
                    A[n][m] = A[n-1][i];
                }
            }
        }
    }   
    cout<<A[N][M]<<endl;
}