#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int dp[1000001] = { 987654321 };
int main() {
	int n = 0;
	cin >> n;
	//dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
	}
	cout << dp[n] <<'\n';
	return 0;
}