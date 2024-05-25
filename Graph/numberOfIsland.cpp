#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

 void dfs(int i,int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or vis[i][j])return ;
        vis[i][j] = 1;

        dfs(i-1, j, grid, vis);
        dfs(i+1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i, j-1, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(row, vector<int> (col, 0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]==0 and grid[i][j]=='1'){
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }

int main(){
    int n, m;cin>>n>>m;
    vector<vector<char>>vv;
    for(int i=0;i<n;i++){
        vector<char>v;
        for(int j=0;j<m;j++){
            char x;cin>>x;
            v.push_back(x);
        }
        vv.push_back(v);
    }
    cout<<numIslands(vv)<<endl;

}