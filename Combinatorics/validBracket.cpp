#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

bool vbs(string s){
    int no = 0, nc = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(')no++;
        else nc++;
        if(no<nc)return false;
    }
    if(no!=nc)return false;
    return true;
}

int main(){
    cout<<vbs("((())(())())")<<endl;
}