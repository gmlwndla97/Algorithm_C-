#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
pair <pair<string, int>,pair<int, int>> v[100001];
bool compare(pair <pair<string, int>, pair<int, int>> a,
	pair <pair<string, int>, pair<int, int>> b) {
	if (a.first.second == b.first.second && a.second.first == b.second.first
		&& a.second.second== b.second.second){
		return a.first.first < b.first.first;
	}
	else if (a.first.second == b.first.second
		&& a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else if (a.first.second== b.first.second) {
		return a.second.first< b.second.first;
	}
	return a.first.second > b.first.second;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str = "";
		int a, b, c = 90;
		cin >> v[i].first.first >> v[i].first.second
			>> v[i].second.first >> v[i].second.second;
	}
	sort(v, v + n, compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].first.first << '\n';
	}
	
	return 0;
}