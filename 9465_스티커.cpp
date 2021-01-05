#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int dp[2][100001] = { 0 };
int sum[2][100001] = { 0 };
int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		for (int k = 0; k < 2; k++) {
			for (int l = 1; l <= n; l++) {
				cin >> dp[k][l];
			}
		}

		sum[0][1] = dp[0][1];
		sum[1][1] = dp[1][1];
		for (int j = 2; j <= n; j++) {
			sum[0][j] = max(sum[1][j - 1], sum[1][j - 2]) + dp[0][j];
			sum[1][j] = max(sum[0][j - 1], sum[0][j - 2])+ dp[1][j];
		}
		cout << max(sum[0][n], sum[1][n]) << '\n';
 	}
	return 0;
}