#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m = 0;
int map[301][301] = { 0 };
int zero[301][301] = { 0 };
int visit[301][301] = { 0 };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;
void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (visit[nx][ny] == 0 && map[nx][ny] != 0) {
				dfs(nx, ny);
			}
		}
	}
	return;
}
int cal(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (map[nx][ny] == 0) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	//먼저 두덩이 이상이면 확인하고 바로 종료 
	int island = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && visit[i][j] == 0) {
				dfs(i, j);
				island++;
				if (island >= 2) {
					cout << 0 << '\n';
					return 0;
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));

	int year = 1;
	while (1) {
		flag = false;
		for (int i = 0; i < v.size(); i++) {
			int x, y, count = 0;
			x = v[i].first;
			y = v[i].second;
			count= cal(x, y);
			zero[x][y] = count;
		}
		for (int i = 0; i < v.size(); i++) {
			int x, y = 0;
			x = v[i].first;
			y = v[i].second;
			if (map[x][y] - zero[x][y] < 0) {
				map[x][y] = 0;
			}
			else
				map[x][y] -= zero[x][y];
		}
		//이제 빙산계산 끝
		//그러면 이제 몇덩어리인지 확인해야됨
		island = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0 && visit[i][j]==0) {
					flag = true;
					dfs(i, j);
					
					island++;
					if (island >= 2) {
						cout << year << '\n';
						return 0;
					}
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		memset(zero, 0, sizeof(zero));
		if (flag == false) {
			cout << 0 << endl;
			break;
		}
		year++;
	}
	return 0;
}