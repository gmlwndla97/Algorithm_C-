#include<iostream>
using namespace std;
int dp[1001][10] = { 0 };
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (j <= k) {
					dp[i][j] += dp[i - 1][k] % 10007;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}
	cout << ans%10007 << '\n';
	return 0;
}
