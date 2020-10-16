#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001] = { 0 };
void swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return;
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int maxidx = 0;
	for (int i = n - 1; i >= 1; i--) {
		maxidx = i;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[maxidx] < arr[j]) {
				maxidx = j;
			}
		}
		swap(maxidx, i);
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " \n";
	}
	return 0;
}