#include<iostream>

using namespace std;

const int N = 1e2;

void bubble_sort(int arr[], int n) {
	for (int i = n - 1; i > 0; i--) {
		bool exchange = false;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				exchange = true;
			}
		}
		if (!exchange) return;
	}
}

int main() {
	int n, q[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];
	bubble_sort(q, n);
	for (int i = 0; i < n; i++) cout << q[i] << " ";

	system("pause");
	return 0;
}