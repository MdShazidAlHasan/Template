#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e7 +10;
vector<bool>isPrime(N, 1);

int main(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<100;i++){
        cout<<isPrime[i]<<endl;
        if(isPrime[i])cnt++;
    }
    cout<<cnt<<endl;
}