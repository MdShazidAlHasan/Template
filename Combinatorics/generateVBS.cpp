#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;

vector<string> generate(int n){
    if(n==0){
        return {""};
    }
    vector<string>complete_sequence;
    for(int i=0;i<=n-1;i++){
        vector<string>inside_bracket = generate(i);
        vector<string>outside_bracket = generate(n-i-1);
        for(string a:inside_bracket){
            for(string b: outside_bracket){
                string concated = "("+a+")"+b;
                complete_sequence.push_back(concated);
            }
        }
    }
    return complete_sequence;
}

int main(){
    
}