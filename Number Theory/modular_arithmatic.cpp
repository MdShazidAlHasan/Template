//(a+b)%m = ((a%m)+(b%m))%m
//(a-b)%m = ((a%m)-(b%m))%m
//(a*b)%m = ((a%m)*(b%m))%m
//(a/b)%m = ((a%m)*(b^-1)%m)%m

/*
Given a nmber N. Print its factorial Constraint 1 <= N <= 100
print answer module M where M = 47 
A % M <47
*/

#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    int n;
    cin >> n;
    ll fact = 1, m = 47;   
    for(int i=2;i<=n;i++){
        fact = ((fact%m)*(n%m))%m;
    }
    cout<<fact<<endl;
}