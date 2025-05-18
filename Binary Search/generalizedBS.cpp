#include <bits/stdc++.h>

using namespace std;

bool isOk(int num){
    return true;
}

int main(){
    long long n;cin>>n;
    long long l = 0, r = n;
    while(l<r){
        int mid = (l+r)/2;
        if(isOk(mid)==0) l = mid + 1;
        else r = mid;
    }
    cout<< l - 1<<endl;
}