#include <bits/stdc++.h>

using namespace std;


// for spiral travel in a matrix
/*
    8 7 6
    1 0 5
    2 3 4
            
*/

int main(){
    int n;cin>>n;
    vector<vector<int>>ans(n+1, vector<int>(n+2, -1));
    int i = 0, j = 0, pi = 0, pj = 0, num = n*n-1, d = 0;
    while(num>=0){
        if(ans[i][j]!=-1 or i<0 or i>=n or j<0 or j>=n){
            d++;
            d %= 4;
            i = pi, j = pj;
        }else{
            ans[i][j] = num;
            pi = i;pj = j;
            num--;
        }
        if(d==0)j++;
        if(d==1)i++;
        if(d==2)j--;
        if(d==3)i--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}