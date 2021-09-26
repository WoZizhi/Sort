#include<iostream>

using namespace std;

const int N = 1e2;

void select_sort(int arr[], int num) {
    int tmp, min_num;
    for (int i = 0; i < num - 1; i++) {
        min_num = i;
        for (int j = i + 1; j < num; j++) if (arr[min_num] > arr[j]) min_num = j;
        if (min_num != i) {
            tmp = arr[min_num];
            arr[min_num] = arr[i];
            arr[i] = tmp;
        }
    }
}

int main() {
	int n, q[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];
    select_sort(q, n);
	for (int i = 0; i < n; i++) cout << q[i] << " ";

	system("pause");
	return 0;
}