#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;
int t = 0;
int n = 0;
int v[100001] = { 0 };
int visit[100001] = { 0 };
int finished[100001] = { 0 }; //����Ŭ �˻� �� ������ �Ⱥ��� �Ǵ� �迭
int ans = 0;
int student = 0;
int head = 0;
void dfs(int start) {
	visit[start] = 1;
	int next = v[start];

	if (visit[next] == 0) {
		dfs(next);
	}
	else { //���� ������ ��尡 �̹� �湮�� �����
		//����Ŭ �˻縦 �ؾߵ�
		//��尡 �������� �� �������� ������ ����Ŭ�� ��ġ��
		//��������
		//���� ��� �������� ���� ������ ����Ŭ��
		//���� ����.
		
		if (finished[next] == false) {
			//�ϴ� �ڱ��ڽ��� ���ش�.
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