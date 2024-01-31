#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;
int binMultiply(int a, int b);

int binExpIter(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = binMultiply(ans, a);
        }
        a = binMultiply(a, a);
        b>>=1;
    }
    return ans;
}
int binMultiply(int a, int b){
    int ans = 0;
    while(b>0){
        if(b&1){
            ans += a;
        }
        a +=a;
        b>>=1;
    }
    return ans;
}
int main(){
    int a = 2, b = 10;
     
    cout<<binExpIter(2, 5)<<endl;
}