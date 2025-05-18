// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    char grid[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int visited[n][m];
    memset(visited, 0, sizeof visited);
    int count = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] or grid[i][j]=='#')continue;
            count++;
            queue<pair<int, int>>q;
            q.push({i, j});
            visited[i][j] = 1;
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                int u = p.first;
                int v = p.second;
                for(int k = 0;k<4;k++){
                    int r = u + dx[k];
                    int c = v + dy[k];
                    if(r>=0 and r<n and c>=0 and c<m){
                        if(visited[r][c]==0 and grid[r][c]=='.'){
                            q.push({r, c});
                            visited[r][c] = 1;
                        }
                    }
                }
            }
        }
    }
    cout<<count;
}