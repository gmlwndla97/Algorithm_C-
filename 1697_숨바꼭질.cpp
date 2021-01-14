#include<iostream>
#include<queue>
using namespace std;
int visit[200001] = { 0 };
queue<pair<int, int>> q;
int main() {
	int n, k = 0;
	cin >> n >> k;
	visit[n] = 1;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
 		if (now == k) {
			cout << cnt << '\n';
			break;
		}
		if (visit[now - 1] == 0 && (now - 1) >= 0 && (now - 1) <= 100000) {
			visit[now - 1] = 1;
			q.push(make_pair(now - 1, cnt + 1));
		}
		if (visit[now + 1] == 0 && (now + 1) >= 0 && (now + 1) <= 100000) {
			visit[now + 1] = 1;
			q.push(make_pair(now + 1, cnt + 1));
		}
		if (visit[now *2] == 0 && (now * 2) >= 0 && (now * 2) <= 100000) {
			visit[now * 2] = 1;
			q.push(make_pair(now * 2, cnt + 1));
		}
	}
	return 0;
}
