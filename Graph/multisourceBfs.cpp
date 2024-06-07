#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int inf = 1e9;
int val[N][N];
int vis[N][N];
int level[N][N];
int n, m;

vector<pair<int, int>>movements = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0},
    {1, 1}, {-1, 1},
    {-1, -1}, {1, -1}
};

bool isValid(int x, int y){
    return x>=0 and y>=0 and x<n and y<m;
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j] = 0;
            level[i][j]=inf;
        }
    }
}
int bfs(){
    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mx = max(mx, val[i][j]);
        }
    }
    queue<pair<int, int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx == val[i][j]){
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        // cout<<v_x<<v_y<<endl;
        q.pop();
        for(auto mv: movements){
            int child_x = mv.first + v_x;
            int child_y = mv.second + v_y;
            if(isValid(child_x, child_y) and !vis[child_x][child_y]){
                q.push({child_x, child_y});
                level[child_x][child_y] = level[v_x][v_y]+1;
                vis[child_x][child_y] = 1;
                ans = max(ans, level[child_x][child_y]);
            }
        }
    }
    return ans;
}



int main(){
    int t;cin>>t;
    while(t--){
        reset();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>val[i][j];
        }
        cout<<bfs()<<endl;
    }
}