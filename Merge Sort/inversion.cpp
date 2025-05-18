#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    long long inv_count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            inv_count += (mid - i + 1);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    for (int k = left; k <= right; ++k) {
        arr[k] = temp[k - left];
    }
    return inv_count;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    long long inv_count = 0;
    inv_count += mergeSortAndCount(arr, left, mid);
    inv_count += mergeSortAndCount(arr, mid + 1, right);
    inv_count += mergeAndCount(arr, left, mid, right);

    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (auto &x : arr) cin >> x;

    cout << mergeSortAndCount(arr, 0, n - 1) << endl;
    
    return 0;
}
