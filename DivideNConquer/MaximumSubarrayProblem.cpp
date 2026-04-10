#include <bits/stdc++.h>
using namespace std;


int maxCrossSum(vector<int>& arr, int s, int mid, int e) {

  int sum = 0;
  int left_sum = INT_MIN;

  for(int i = mid; i >= 0; i--) {
    sum += arr[i];
    left_sum = max(left_sum, sum);
  }

  sum = 0;
  int right_sum = INT_MIN;

  for(int j = mid; j < e; j++) {
    sum += arr[j];
    right_sum = max(right_sum, sum);
  }

  return left_sum + right_sum;
}


int MaximumSubarray(vector<int>& arr, int s, int e) {

  if(s >= e) return arr[s];
  
  int mid = s + (e - s) / 2;
  
  int rss = MaximumSubarray(arr,s, mid);
  int lss = MaximumSubarray(arr,mid+1, e);
  int css = maxCrossSum(arr,s,mid,e);

  return max({rss,lss,css});
  
} 


int main(){

  vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

  int result = MaximumSubarray(arr, 0, arr.size() - 1);
  cout << "The Maximum Subarray Value : " << result << endl;
}
