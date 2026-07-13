#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int isolve(int n, int x, int arr[]) {
	if (x == 0) return 0;
	if (x < 0) return INF;
	
	vector<int> dp(x+1, INF);
	dp[0] = 0;
	
	for(int i = 1; i <= x; i++) {
		dp[i] = INF;
		for(int j = 0; j < n; j++) {
			if (i-arr[j] >= 0) {
				dp[i] = min(dp[i], dp[i-arr[j]] + 1);
			}
		}
	}
	
	return (dp[x] == INF ? -1 : dp[x]);
}	
/*
int solve(int n, int x, int arr[], int value[], bool ready[]) {
	if (x == 0) return 0;
	if (x < 0) return INF;
	if (ready[x]) return value[x];
	int best = INF;

	for(int i = 0; i < n; i++){
		int res = solve(n,x-arr[i],arr,value,ready);
		if(res != INF){
			best = min(best, res+1);
		}
	}
	value[x] = best;
	ready[x] = true;

	return best;

}
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	int arr[n];
	[[maybe_unused]]int value[x+1];
	[[maybe_unused]]bool ready[x+1] = {false};
	for(int i = 0; i < n;i++){
		cin >> arr[i];
	}

	int res = isolve(n,x,arr);
	cout << res << endl;
//	int out = solve(n,x,arr,value,ready);
//	cout << (out == INF ? -1 : out) << endl;

	return 0;
}
