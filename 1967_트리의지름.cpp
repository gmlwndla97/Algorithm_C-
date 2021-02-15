#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v[10001];
queue<int> q;
int visit[10001] = { 0 };
int dist[10001] = { 0 };
int n = 0;
void bfs(int start) {
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int adj = 0;
			int cost = 0;
			adj = v[now][i].first;
			cost = v[now][i].second;
			if (visit[adj] == 0) {
				visit[adj] = 1;
				q.push(adj);
				if (dist[now] + cost > dist[adj]) {
					dist[adj] = dist[now] + cost;
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int p, c, w = 0;
		cin >> p >> c >> w;
		v[p].push_back(make_pair(c, w));
		v[c].push_back(make_pair(p, w));
	}
	bfs(1);
	int maxIdx = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > dist[maxIdx]) {
			maxIdx = i;
		}
	}
	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(dist));
	bfs(maxIdx);

	int maxval = dist[maxIdx];
	for (int i = 2; i <= n; i++) {
		cout << dist[i] << " ";
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] > maxval) {
			maxval = dist[i];
		}
	}
	cout << maxval << '\n';
	return 0;
}