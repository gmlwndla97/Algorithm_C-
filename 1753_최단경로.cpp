#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<functional>
using namespace std;
int v, e, k = 0;
vector<pair<int,int>> map[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int d[20001];
void dik(int start) {
	pq.push(make_pair(0, k));
	while (!pq.empty()) {
		int nowweight = pq.top().first;
		int nownode = pq.top().second;
		pq.pop();
		//이제 인접노드 탐색
		for (int i = 0; i < map[nownode].size(); i++) {
			int sidenode = map[nownode][i].first;
			int sidecost = map[nownode][i].second;
			if (sidecost + d[nownode] < d[sidenode]) {
				d[sidenode] = sidecost + d[nownode]; //갱신해주고
				pq.push(make_pair(d[sidenode], sidenode));
			}
		}
	}
}
int main() {
	cin >> v >> e;
	cin >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w = 0;
		cin >> u >> v >> w;
		map[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= v; i++) {
		d[i] = 987654321;
	}
	d[k] = 0; //시작점 0으로 세팅하고
	//다익스트라 호출하기
	dik(k);
	for (int i = 1; i <= v; i++) {
		if (d[i] == 987654321) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}
	return 0;
}