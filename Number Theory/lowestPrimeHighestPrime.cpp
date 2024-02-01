#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e7 +10;
vector<bool>isPrime(N, 1);
vector<int>lp(N, 0), hp(N, 0);
int main(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            lp[i] = hp[i] = i;
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j]==0)lp[j] = i;
            }
        }
    }
    int cnt = 0;
    // highest prime and lowest prime

    // for(int i=1;i<100;i++){
    //     cout<<lp[i]<<' '<<hp[i]<<endl;
    // }
    
    //prime factors using seive
    int num;
    cin>>num;
    vector<int>prime_factors;
    
    while(num>1){
        int prime_factor = hp[num];
        while(num%prime_factor==0){
            num /= prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }
    for(int i=0;i<prime_factors.size();i++)
        cout<<prime_factors[i]<<endl;
} 