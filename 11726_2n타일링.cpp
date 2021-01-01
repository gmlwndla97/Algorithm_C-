#include<iostream>
using namespace std;
long long  dp[1001] = { 0 };
int main() {
	int n = 0;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1]%10007 + dp[i - 2]%10007;
	}
	cout << (dp[n]%10007) << '\n';
	return 0;
}