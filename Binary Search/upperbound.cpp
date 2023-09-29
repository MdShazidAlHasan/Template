#include <bits/stdc++.h>
#define ll long long 
#define all(x) x.begin(), x.end()

using namespace std;
int custom_upper_bound(const std::vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
int main(){
    vector<int> vec = {10, 20, 30, 40, 50};
    cout<<custom_upper_bound(vec, 25);
}