#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, ans = 0;
int d[1001];
int map[1001][1001] = { 0 };
int visit[1001] = { 0 };
vector<int> v;
int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c = 0;
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	for (int i = 2; i <= n; i++) {
		d[i] = 987654321;
	}
	d[1] = 0; //������ 1�� ����
	for (int i = 1; i <= n; i++) {
		if (map[1][i] != 0) {
			d[i] = map[1][i];
		}
	}
	//���� 1���� �信 �ְ� while�� �������.
	v.push_back(1);
	visit[1] = 1;

	while (v.size() < n) {
		int minval = 987654321;
		int minidx = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				if (d[i] < minval) {
					minval = d[i];
					minidx = i;
				}
			}
		}
		//������� ���� �ּ��� d�� �˰���.
		ans += d[minidx];
		visit[minidx] = 1;
		v.push_back(minidx);
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				if (d[i] > map[minidx][i] && map[i][minidx]!=0) {
					d[i] = map[minidx][i]; //����
				}
			}
		}
		//for (int i = 1; i <= n; i++) {
		//	cout << d[i] << " ";
		//}
		//cout << endl;
	}
	cout << ans << '\n';
	return 0;
}