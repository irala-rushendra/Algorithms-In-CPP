#include <bits/stdc++.h>

using namespace std;




int MatrixChainMultiplication(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {

  if(dp[i][j] != -1) return dp[i][j];
  if(i == j) return 0;

  int minValue = INT_MAX;

  for(int k = i; k < j; k++) {
    int steps = MatrixChainMultiplication(arr,i,k,dp) + MatrixChainMultiplication(arr,k+1,j,dp) + arr[i-1] * arr[k] * arr[j];

    minValue = min(minValue, steps);
  }

  return dp[i][j] = minValue;
} 

int main() {

  vector<int> arr = {40,20,10,30,70};
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n , -1));

  cout << "Minimum Value: " << MatrixChainMultiplication(arr,1,n-1,dp) << endl;
}
