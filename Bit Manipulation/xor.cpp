#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    // swap two numbers using xor
    int a = 4, b = 6;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<' '<<b<<endl;

    /*
    Given array a of n integers. All integers are present
    in even count except one. Find that integer which
    has odd count in O(N) time complexity and O(1) space;
    N<10^5
    a[i]<10^5
    */
    int ans = 0;
    for(int i=0;i<5;i++){
        int x;cin>>x;
        ans ^= x;
    }
    cout<<ans<<endl;

}