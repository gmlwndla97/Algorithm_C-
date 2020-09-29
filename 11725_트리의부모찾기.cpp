#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n = 0;
vector<int> map[100001];
vector<int> child[100001];
int visit[100001] = { 0 };
int idx[100001] = { 0 };
queue<int> q;
int main() {
	cin >> n;
	int i = 0;
	for (i = 0; i < n - 1; i++) {
		int x, y = 0;
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}
	//이제 자식만 담기.
	q.push(1);
	int now = 0;
	while (!q.empty()) {
		now = q.front();
		visit[now] = 1;
		q.pop();
		for (i = 0; i < map[now].size(); i++) {
			if (visit[map[now][i]] == 0) {
				child[now].push_back(map[now][i]);
				visit[map[now][i]] = 1;
				q.push(map[now][i]);
				idx[map[now][i]] = now;
			}
		}
	}
	for (i = 2; i <= n; i++) {
		cout << idx[i] << '\n';
	}
	return 0;
}