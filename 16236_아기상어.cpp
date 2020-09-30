#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
int arr[21][21] = { 0 };
int visit[21][21] = { 0 };
vector<pair<int,pair<int,int>>> fish;
queue<pair<int,pair<int,int>>> q;
int fishSize = 2;
int eat = 0;
int dx[4] = { -1,0,1, 0 };
int dy[4] = { 0,-1,0,1 };
int start_x = 0;
int start_y = 0;
int sum = 0;
int now_cnt = 0;
int fishcount = 0;
int idx = 0;
queue<pair<int, pair<int,int>>> st;
int stepcount = 0;
void step(int now_x, int now_y, int x, int y) {
	 stepcount = 0;
	
	while (!st.empty()) {
		int dest_x = st.front().second.first;
		int dest_y = st.front().second.second;
		stepcount = st.front().first;
		q.pop();
		if (dest_x == x && dest_y == y) { //도착까지 거리
			sum += stepcount;
		}
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now_x;
			int ny = dy[i] + now_y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					st.push(make_pair(stepcount++, make_pair(nx, ny)));
				}
			}
		}
	}
}
void bfs() {
	arr[start_x][start_y] = 0;
	int cnt = 1;
	q.push(make_pair(cnt, make_pair(start_x, start_y)));
	while (!q.empty()) {
		now_cnt = q.front().first;
		//cout << " now_cnt " << now_cnt << endl;
		int now_x = q.front().second.first;
		int now_y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now_x;
			int ny = dy[i] + now_y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (arr[nx][ny] <= fishSize ) {
					if (arr[nx][ny] < fishSize && arr[nx][ny] != 0) {
						//먹을 수 있는 애면
						//먼저먹음
						cout << nx << " " << ny << endl;
						eat++;
						if (fishSize == eat) {
							fishSize++;
							eat = 0;
						}
						
						//cout << now_cnt << endl;
						//now_cnt = 0;

						idx++;
						step(now_x, now_y, nx, ny);
						arr[nx][ny] = 0;
						sum += stepcount;
						

					}
					//지나갈수있으면 그냥 push
					else
						
						q.push(make_pair(now_cnt++, make_pair(nx, ny)));

				}
			}
		}
		if (fish[idx].first>=fishSize) return;
		cout << "여길왜..";
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				fish.push_back(make_pair(arr[i][j], make_pair(i,j)));
				fishcount++;
			}
			if (arr[i][j] == 9) {
				start_x = i;
				start_y = j;
			}
		}
	}
	sort(fish.begin(), fish.end());
	//계속 돌면서 자기 보다 크기 작은 물고기 있는지 확인
	bfs();
	cout << sum << endl;
	
}