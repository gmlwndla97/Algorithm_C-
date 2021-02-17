#include<iostream>
#include<vector>
#include<memory.h>
#include<string>
using namespace std;
vector<int> map[20001];
int visit[20001] = { 0 };
int k = 0;
int v = 0;
int e = 0;
bool flag = true; //�̺б׷�������
bool color[20001] = { false };
void dfs(int start) {
	visit[start] = 1;
	for (int i = 0; i < map[start].size(); i++) {
		int num = map[start][i];
		if (visit[num] == 0) {
			//�湮���� �������̶��
			// ���� �ٸ������� �ش�.
			color[num] = !color[start];
			dfs(num);

		}
		else {
			if (color[num] == color[start]) {
				//���� ���� �����̶��
				//�̺б׷��� Ż���ΰ���.
				flag = false;
				return;
			}
		}
	}
//	dfs(num);
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		for (int j = 0; j < e; j++) {
			int x, y = 0;
			cin >> x >> y;
			map[x].push_back(y);
			map[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (visit[i] == 0) {
				dfs(i);
			}
		}
		if (flag) {
			cout << "YES" << '\n';
		}
		else cout << "NO" << '\n';
		memset(visit, 0, sizeof(visit));
		memset(color, false, sizeof(color));
		for (int s = 0; s <= 20001; s++) {
			map[s].clear();
		}
	}
	
	
	return 0;
}