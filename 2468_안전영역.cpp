#include<iostream>
#include<memory.h>
#include <functional>
#include<vector>
#include<algorithm>
using namespace std;
int n = 0;
int visit[101][101] = { 0 };
int map[101][101] = { 0 };
int copymap[101][101] = { 0 };
int maxval = 0;
int minval = 987654321;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> v;
void dfs(int x, int y, int height){
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] > height && visit[nx][ny] == 0) {
				dfs(nx, ny, height);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxval) maxval = map[i][j];
			if(map[i][j]<minval) minval=map[i][j];

		}
	}
	int answer = 0;
	for (int k = 0; k <= maxval; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > k && visit[i][j] == 0) {
					dfs(i, j, k);
					answer++;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		v.push_back(answer);
		answer = 0;
	}
	sort(v.begin(), v.end(), greater<int>());
	cout << v[0] << '\n';
	return 0;
}