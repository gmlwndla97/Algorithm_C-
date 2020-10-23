#include<iostream>
#include <vector>
#include<memory>
using namespace std;
int w, h = 0;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int map[51][51] = { 0 };
int visit[51][51] = { 0 };
void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
				dfs(nx, ny);
			}
		}
		
	}
	return;
}
int main() {

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			return 0;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}