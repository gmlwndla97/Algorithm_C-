#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;
int t = 0;
int n = 0;
int v[100001] = { 0 };
int visit[100001] = { 0 };
int finished[100001] = { 0 }; //사이클 검사 다 끝나서 안봐도 되는 배열
int ans = 0;
int student = 0;
int head = 0;
void dfs(int start) {
	visit[start] = 1;
	int next = v[start];

	if (visit[next] == 0) {
		dfs(next);
	}
	else { //다음 가야할 노드가 이미 방문된 노드라면
		//사이클 검사를 해야됨
		//노드가 끝나려면 맨 마지막은 무조건 사이클을 거치고
		//끝나야함
		//다음 노드 기준으로 보면 무조건 사이클이
		//있을 것임.
		
		if (finished[next] == false) {
			//일단 자기자신은 세준다.
			ans++;
			for (int i = next; i != start; i = v[i]) {
				ans++;
			}
		}

	}

	if (finished[start] == 0) {
		finished[start] = 1;
	}
	return;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			int x = 0;
			cin >> x;
			v[j]=x;
		}
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 0) {
				dfs(j);
			}
		}
		cout << n-ans << '\n';
		ans = 0;
		memset(v, 0, sizeof(v));
		memset(visit, 0, sizeof(visit));
		memset(finished, 0, sizeof(finished));
	}
	
	return 0;
}