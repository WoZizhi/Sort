#include<iostream>

using namespace std;

const int N = 1e2;
void heap_adjust(int arr[], int root, int num);

void heap_build(int arr[], int num) {
    for (int i = num - 2 >> 1; i >= 0; i--) heap_adjust(arr, i, num);
}

void heap_adjust(int arr[], int root, int num) {
    int largest = root, leftnode = 2 * root + 1, rightnode = 2 * root + 2;
    if (leftnode < num && arr[leftnode] > arr[largest]) largest = leftnode;
    if (rightnode < num && arr[rightnode] > arr[largest]) largest = rightnode;
    if (largest != root) {
        int tmp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = tmp;
        heap_adjust(arr, largest, num);
    }
}

void heap_sort(int arr[], int num) {
    if (num < 2) return;
    heap_build(arr, num);
    while (--num) {
        int tmp = arr[0];
        arr[0] = arr[num];
        arr[num] = tmp;
        heap_adjust(arr, 0, num);
    }
}

int main() {
    int n, q[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];
	heap_sort(q, n);
	for (int i = 0; i < n; i++) cout << q[i] << " ";

	system("pause");
	return 0;
}