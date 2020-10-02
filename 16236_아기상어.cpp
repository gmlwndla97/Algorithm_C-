#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

int n = 0;
int arr[21][21] = { 0 };
int visit[21][21] = { 0 };
vector<pair<int, pair<int, int>>> fish;
queue <pair<int, int>> q;
int fishSize = 2;
int eat = 0;
int dx[4] = { -1,0,1, 0 };
int dy[4] = { 0,-1,0,1 };
int start_x = 0;
int start_y = 0;
int prev_x = 0;
int prev_y = 0;
int sum = 0;
int now_cnt = 0;
int fishcount = 0;
int idx = 0;
int cnt = 0;

void bfs() { //이제 자기로부터 계속 거리 구하기
	q.push(make_pair(start_x, start_y));
	prev_x = start_x;
	prev_y = start_y;
	visit[start_x][start_y] = 1;
	while (idx==fish.size()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		//int now_cnt = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now_x;
			int ny = dy[i] + now_y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (visit[nx][ny] == 0 && arr[nx][ny] <= fishSize) {
					if (arr[nx][ny] < fishSize && arr[nx][ny]!=0) {
						//먹을수 있으면
						eat++; 
						arr[nx][ny] = 0;
						memset(visit, 0, sizeof(visit));
						//물고기 사이즈업
						if (eat == fishSize) {
							fishSize++;
							eat = 0;
						}
						cout << "원래 위치" << prev_x << " " << prev_y << '\n';
						cout << "먹은애 위치" << nx << " " << ny << '\n';
						cout << (abs(prev_x - nx)) << "+" << abs(prev_y - ny) << '\n';
						cnt += (abs(prev_x - nx) + abs(prev_y - ny));
						prev_x = nx;
						prev_y = ny;
						while (!q.empty()) q.pop();
						fish.push_back(make_pair(now_cnt++, make_pair(nx, ny)));
						sort(fish.begin(), fish.end());
						q.push(make_pair(fish[0].second.first, fish[0].second.second));
					}
					//먹고 나서 
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j]!=9) {
				fishcount++;
				//fish.push_back(make_pair(make_pair(i, j), arr[i][j]));
			}
			if (arr[i][j] == 9) {
				start_x = i;
				start_y = j;
			}
		}
	}
	//계속 돌면서 자기 보다 크기 작은 물고기 있는지 확인
	bfs();
	cout << cnt << endl;
	
}