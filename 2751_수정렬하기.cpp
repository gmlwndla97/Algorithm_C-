#include <iostream>
using namespace std;
int arr[10000001];
#pragma warning(disable:4996)
int partition(int left, int right) {
	int pivot = arr[left];
	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (arr[i] <= pivot && i <= right) {
			i++;
		}
		while (arr[j] >= pivot && j >= left + 1) {
			j--;
		}

		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//피벗과 high위치를 교환
	int temp = arr[j];
	arr[j] = arr[left];
	arr[left] = temp;
	return j;


}
void quicksort(int left, int right) {
	if (left <= right) {
		int pivot = partition(left, right);
		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}
}



int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}