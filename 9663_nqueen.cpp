#include <iostream>
using namespace std;
int arr[16][16] = { 0 };
int row, col = 0;
int n = 0;
int cnt = 0;
int ans = 0;
int promising(int row, int col) {
	//���� ���Ƶ� �Ǵ��� �˻�
	if (arr[row][col] == 1) return 0;
	
	//1. ������ �˻�
	for (int i = 1; i < row; i++) {
		if (arr[i][col] == 1) {
			return 0;
		}
	}
	//2.�밢�� �˻�
	//2-1. ���� �� �밢�� �˻�

	int x = row-1;
	int y = col-1;
	while (x > 0 && y > 0) {
		if (arr[x][y] == 1) {
			return 0;
		}
		x --;
		y --;
	}
	x = row - 1;
	y = col + 1;
	while (x >0 && y <=n) {
		if (arr[x][y] == 1) {
			return 0;
		}
		x --;
		y ++;
	}
	return 1;
}
void dfs(int row) {
	if (row > n) {
		ans++;
		return;
	}
	for (int i = 1; i <= col; i++) {
		if (promising(row, i) == 1) {
			arr[row][i] = 1;
			dfs(row + 1);
			arr[row][i] = 0;
		}
	}

	return;
}
int main() {
	
	cin >> n;
	row = n;
	col = n; 
	dfs(1);
	cout << ans << '\n';
	return 0;
}