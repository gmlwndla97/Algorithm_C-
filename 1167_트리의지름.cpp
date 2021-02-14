#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;
int v = 0;
queue<int> q;
vector<pair<int,int>> map[100001];
int visit[100001] = { 0 };
int dist[100001] = { 0 };
void bfs(int start) {
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < map[now].size(); i++) {
			int num = map[now][i].first;
			if (visit[num] == 0) {
				visit[num] = 1;
				q.push(num);
				if (dist[now] + map[now][i].second > dist[num]) {
					dist[num] = dist[now] + map[now][i].second;
				}
				

			}
		}
	}
}
int main() {
	cin >> v;
	for (int i = 0; i < v; i++) {
		int x = 0;
		cin >> x;
		while (1) {
			int idx = 0;
			int dist = 0;
			cin >> idx;
			if (idx == -1) break;
			cin >> dist;
			map[x].push_back(make_pair(idx, dist));
		}
	}
	//������ ��忡�� ���� �վָ� ã�´�. �װ� ��Ʈ�̴�.
	bfs(1);
	int maxidx = 1;
	for (int i = 2; i <= v; i++) {
		if (dist[i] > dist[maxidx]) {
			maxidx = i;
		}
	}
	//���� �վ��� �ε����� ���� maxidx
	//�׷� ���� maxidx�κ��� ���� �� �ָ� ã���� �װ� 
	//Ʈ���� ����
	/*
	5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
*/

	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(dist));
	bfs(maxidx);
	int maxval = 0;
	for (int i = 1; i <= v; i++) {
		if (dist[i] > maxval) {
			maxval = dist[i];
		}
	}
	//for (int i = 1; i <= v; i++) {
	//	cout << dist[i] << " ";
	//}
	cout << maxval << '\n';

	return 0;
}