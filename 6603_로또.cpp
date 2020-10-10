#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include<math.h>
#include <functional>
using namespace std;
int k = 0;
int num[14] = { 0 };

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		vector<int> v;
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}


		for (int i = 0; i < 6; i++) {
			v.push_back(1);
		}
		for (int i = 0; i < k - 6; i++) {
			v.push_back(0);
		}
		sort(v.begin(), v.end(), greater<int>());
	
		do {
			for (int i = 0; i < v.size(); i++) {
				//cout << num[i] << " ";
				if (v[i] == 1) {
					cout << num[i] << " ";
				}
			}
			cout << '\n';
		} while (prev_permutation(v.begin(), v.end()));
	}
	
	return 0;
	
}