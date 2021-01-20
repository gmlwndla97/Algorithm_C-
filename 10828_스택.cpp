#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int x = 0;
			cin >> x;
			v.push_back(x);
		}
		else if (str == "pop") {
			if (v.size() == 0) {
				cout << -1 << '\n';
			}
			else {
				cout << v[v.size() - 1] << '\n';
				v.pop_back();
			}
		}
		else if (str == "size") {
			cout << v.size() << '\n';
		}
		else if (str == "empty") {
			if (v.size() == 0) {
				cout << 1 << '\n';
			}
			else cout << 0 << '\n';
		}
		else if (str == "top") {
			if (v.size() == 0) {
				cout << -1 << '\n';
			}
			else cout << v[v.size() - 1] << '\n';
		}
	}
	return 0;
}