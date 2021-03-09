#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n = 0;
int arr[11][11] = { 0 };
vector<int> order;
int temp = 0;
int from = 0;
int to = 0;
int ans = 987654321;
bool flag = false;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		order.push_back(i);
	}
	do {
		temp = 0;
		for (int i = 0; i < n-1; i++) {
			from = order[i];
			to = order[i + 1];
			if (arr[from][to] == 0) {
				flag = true;
				break;
			}
			temp += arr[from][to];			
		}
		if (flag == false) {
			if (arr[order[n - 1]][order[0]] == 0) {
						continue;
					}
					temp += arr[order[n - 1]][order[0]];
					if (temp < ans) {
						ans = temp;
					}
		}
		flag = false;
	} while (next_permutation(order.begin(), order.end()));
	cout << ans << endl;
	return 0;
}