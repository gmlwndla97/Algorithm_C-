#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n = 0;
int arr[1000001];
void downheap(int start, int size) {
	int leftchild = 2 * start;
	int rightchild = 2 * start + 1;
	int bigger = 0;
	if (leftchild <= size && arr[leftchild] > arr[start]) {
		bigger = leftchild;
	}
	else bigger = start;

	if (rightchild <= size && arr[rightchild] > arr[bigger]) {
		bigger = rightchild;
	}
	if (bigger != start) {
		int temp = arr[bigger];
		arr[bigger] = arr[start];
		arr[start] = temp;
		downheap(bigger, size);
	}
	//for (int i = 1; i <= n; i++) {
	//	cout << arr[i] << ' ';
	//}
	//cout << '\n';
}
void buildheap(int size) {
	for (int i = size / 2; i >= 1; i--) {
		downheap(i, size);
	}
}
int main() {
	cin >> n;
	arr[0] = 0; //맨 앞은 비워논다.
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	buildheap(n);
	//cout << "힙 다 만듦" << endl;
	int heapsize = n;
	for (int i = 1; i <= n - 1; i++) {
		int temp = arr[heapsize];
		arr[heapsize] = arr[1];
		arr[1] = temp;
		heapsize--;
		downheap(1, heapsize);
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}