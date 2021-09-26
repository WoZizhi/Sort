#include<iostream>

using namespace std;

const int N = 1e2;

void insert_sort1(int arr[], int n) {
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j-1]) {
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
			else break;
		}
	}
}

void insert_sort2(int arr[], int num) {
	int tmp, l, m, h;
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j], l = 0, h = j;
				while (l < h) {
					m = l + h >> 1;
					if (arr[m] > arr[j]) h = m;
					else {
						l = m + 1;
						if (arr[m] == arr[j]) break;
					}
				}
				for (int i = j; i >= l + 1; i--) arr[i] = arr[i - 1];
				arr[l] = tmp;
			}
			else break;
		}
	}
}


int main() {
	int n, q[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];
	//insert_sort1(q, n);
	insert_sort2(q, n);
	for (int i = 0; i < n; i++) cout << q[i] << " ";

	system("pause");
	return 0;
}