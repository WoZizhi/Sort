#include<iostream>

using namespace std;

const int N = 1e2;

void merge_recursion(int arr[], int l, int r) {
	if (l >= r) return;
	int m = l + r >> 1;
	merge_recursion(arr, l, m), merge_recursion(arr, m + 1, r);
	int* tmp = new int[r - l + 1]{ 0 };
	int index = 0, a = l, b = m + 1;
	while (a <= m && b <= r) {
		if (arr[a] < arr[b]) tmp[index++] = arr[a++];
		else tmp[index++] = arr[b++];
	}
	while (a <= m) tmp[index++] = arr[a++];
	while (b <= r) tmp[index++] = arr[b++];
	for (int i = l, j = 0; i <= r; i++, j++) arr[i] = tmp[j];

	delete[] tmp;
	tmp = nullptr;
}

void merge_non_recursion(int arr[], int n) {
    int k = 1, a, b;
    while (k < n) {
        int cur = 0, l = 0, m = k, h = 2 * k;
        int* tmp = new int[n] {0};
        while (h <= n) {
            a = l, b = m;
            while (a < m && b < h) {
                if (arr[a] <= arr[b]) tmp[cur++] = arr[a++];
                else tmp[cur++] = arr[b++];
            }
            while (a < m) tmp[cur++] = arr[a++];
            while (b < h) tmp[cur++] = arr[b++];
            l = h, m = h + k, h = h + 2 * k;
        }
        if (m < n) {
            a = l, b = m;
            while (a < m && b < n) {
                if (arr[a] <= arr[b]) tmp[cur++] = arr[a++];
                else tmp[cur++] = arr[b++];
            }
            while (a < m) tmp[cur++] = arr[a++];
            while (b < n) tmp[cur++] = arr[b++];
        }
        for (int i = 0, j = 0; i < b; i++, j++) arr[i] = tmp[j];
        k *= 2;

        delete[] tmp;
        tmp = nullptr;
    }
}


int main() {
	int n, q[N];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];
	//merge_recursion(q, 0, n-1);
	merge_non_recursion(q, n);
	for (int i = 0; i < n; i++) cout << q[i] << " ";

	system("pause");
	return 0;
}