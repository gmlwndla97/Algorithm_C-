#include<iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
char arr[101][101] = { "" };
int visit[101][101] = { 0 };

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	//1. 가로 먼저
	int cnt = 0;
	int rownum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') {
				cnt++;
			
			}
			else if(arr[i][j]=='X' && cnt!=0) {
				if (cnt >= 2) {
					rownum++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2) {
			rownum++;
		}
		cnt = 0;
	}

	//2.세로
	cnt = 0;
	int colnum = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == '.') {
				cnt++;

			}
			else if (arr[i][j] == 'X' && cnt != 0) {
				if (cnt >= 2) {
					colnum++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2) {
			colnum++;
		}
		cnt = 0;
	}
	cout <<rownum << " " <<  colnum << '\n';
	return 0;
}