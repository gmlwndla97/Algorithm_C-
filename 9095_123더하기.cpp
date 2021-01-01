#include<iostream>
using namespace std;

int dp[12] = { 0 };
int main() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	int t, n = 0;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}

	return 0;
}