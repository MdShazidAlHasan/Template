#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
bool vis[N];

void dfs(int i,int j, int initialColor, int newColor, vector<vector<int>>& image){
    int n = image.size();
    int m = image[0].size();
    if(i<0 or j<0)return ;
    if(i>=n or j>=m)return ;
    if(image[i][j]!=initialColor)return ;
    image[i][j] = newColor;

    dfs(i-1, j, initialColor, newColor, image);
    dfs(i+1, j, initialColor, newColor, image);
    dfs(i, j+1, initialColor, newColor, image);
    dfs(i, j-1, initialColor, newColor, image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    dfs(sr, sc, initialColor, color, image);
    return image;
}
int main(){
    int n, m;cin>>n>>m;
    vector<vector<int>>vv;
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<m;j++){
            int x;cin>>x;
            v.push_back(x);
        }
        vv.push_back(v);
    }
    floodFill(vv, 1, 1, 2);
    for(auto v:vv){
        for(auto e:v)cout<<e<<' ';
        cout<<endl;
    }
}