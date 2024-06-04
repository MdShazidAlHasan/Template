// https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+10;
const int N = 1e5;
vector<int> graph[N];
int vis[8][8];
int level[8][8];

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1]-'1';
}
bool isValid(int x, int y){
    return x>=0 and y>=0 and x<8 and y<8;
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            vis[i][j] = 0;
            level[i][j] = 0;
        }
    }
}
vector<pair<int, int>>movements{
    {-1, 2}, {1, 2},
    {-1, -2}, {1, -2},
    {2, -1}, {2, 1},
    {-2, -1}, {-2, 1},
};

int bfs(string source, string dest){
    reset();
    int sx = getX(source);
    int sy = getY(source);
    int dx = getX(dest);
    int dy = getY(dest);

    queue<pair<int, int>>q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while(!q.empty()){
        auto cur_v = q.front();
        q.pop();
        int x = cur_v.first, y = cur_v.second;
        for(auto mv: movements){
            int cx = mv.first + x;
            int cy = mv.second + y;
            if(isValid(cx, cy) and !vis[cx][cy]){
                q.push({cx, cy});
                vis[cx][cy] = 1;
                level[cx][cy] = level[x][y] + 1;
            }
        }
    }
    return level[dx][dy];
}



int main(){
    int T;cin>>T;
    while(T--){
        string s1, s2;cin>>s1>>s2;
        cout<<bfs(s1, s2)<<endl;
    }
}