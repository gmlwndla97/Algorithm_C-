#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<functional>
using namespace std;
int n, m = 0;
vector<pair<int, int>> map[1001];
int d[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dik(int start) {
	while (!pq.empty()) {
		int nowweight = pq.top().first;
		int nownode = pq.top().second;
		pq.pop();
		for (int i = 0; i < map[nownode].size(); i++) {
			int sidenode = map[nownode][i].first;
			int sideweight = map[nownode][i].second;
			if (d[sidenode] > d[nownode] + sideweight) {
				d[sidenode] = d[nownode] + sideweight;
				pq.push(make_pair(d[sidenode], sidenode));
			}
			
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w = 0;
		cin >> u >> v >> w;
		map[u].push_back(make_pair(v, w));
	}
	int start, dest = 0;
	cin >> start >> dest;
	for (int i = 1; i <= n; i++) {
		d[i] = 987654321;
	}
	d[start] = 0;
	pq.push(make_pair(d[start], start));
	dik(start);
	cout << d[dest] << '\n';
	return 0;
}