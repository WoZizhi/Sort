#include<iostream>

using namespace std;

const int N = 1e2;

void shell_sort(int arr[], int num) {
    int gap = num / 2, tmp;
    while (gap > 0) {
        for (int i = 0; i < num - gap; i++) {
            for (int j = i + gap; j >= gap; j -= gap) {
                if (arr[j] < arr[j - gap]) {
                    tmp = arr[j];
                    arr[j] = arr[j - gap];
                    arr[j - gap] = tmp;
                }
                else break;
            }
        }
        gap /= 2;
    }
}

int main() {
	int n, q[N];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	shell_sort(q, n);
	for (int i = 0; i < n; i++) {
		cout << q[i] << " ";
	}

	system("pause");
	return 0;
}