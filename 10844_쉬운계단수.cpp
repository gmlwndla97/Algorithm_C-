#include<iostream>
using namespace std;

int dp[101][101] = { -1 };
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= 9; i++) dp[i][0] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = dp[i - 1][j - 1] % 1000000000 +
				dp[i - 1][j + 1] % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
		dp[i][0] = dp[i - 1][1] % 1000000000;
	}
	long long ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += dp[n][i] % 1000000000;
	}
	cout << ans % 1000000000 << '\n';
	return 0;
}