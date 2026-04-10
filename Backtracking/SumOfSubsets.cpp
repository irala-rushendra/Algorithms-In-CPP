#include<bits/stdc++.h>
using namespace std;

void findSubsets(int arr[], int n, int target, int idx, vector<int>& cur) {
    if (target == 0) {
        for (int x : cur) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = idx; i < n; i++) {
        if (arr[i] <= target) {
            cur.push_back(arr[i]);                          // choose
            findSubsets(arr, n, target-arr[i], i+1, cur);  // explore
            cur.pop_back();                                 // backtrack
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 2, 2};
    int n = 5, target = 6;
    vector<int> cur;
    cout << "Subsets that sum to " << target << ":\n";
    findSubsets(arr, n, target, 0, cur);
    return 0;
}

