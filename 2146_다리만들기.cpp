#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int map[101][101] = { 0 };
int dist[101][101] = { 0 };
int visit[101][101] = { 0 };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 1;
int n = 0;
int depth = 0;
int minval = 987654321;
queue<pair<int, int>> q;
void dfs(int x, int y) {
	visit[x][y] = 1;
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
				dfs(nx, ny);
			
			}
		}
	}

}
void bfs(int num) {
	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now_x;
			int ny = dy[i] + now_y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[nx][ny] == 0 && visit[nx][ny] == 0) {
					dist[nx][ny] = dist[now_x][now_y] + 1;
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
				if (map[nx][ny] != 0 && map[nx][ny] != num) {
					depth = dist[now_x][now_y];
					return;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				dfs(i, j);
				cnt += 1;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	for (int k = 1; k < cnt; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] ==k) {
					q.push(make_pair(i, j));
				//	visit[i][j] = 1;
				}
			}
		}
		bfs(k);
		minval = min(minval, depth);
		depth = 987654321;
		while (q.size()) {
			q.pop();
		}
		memset(dist, 0, sizeof(dist));
		memset(visit, 0, sizeof(visit));
		
	}
	cout << minval << '\n';
	return 0;
}