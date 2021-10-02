#include<iostream>

using namespace std;

const int N = 1e2;

void quick_sort(int arr[], int l, int r) {
    if (l >= r) return;
    int pivot = arr[l], i = l, j = r + 1;
    while (true) {
        while (arr[++i] < pivot) if (i == r) break;
        while (arr[--j] > pivot) if (j == l) break;
        if (i >= j) break;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    arr[l] = arr[j];
    arr[j] = pivot;
    quick_sort(arr, l, j - 1);
    quick_sort(arr, j + 1, r);
}

int main() {
    int n, q[N] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) cout << q[i] << " ";
	
    system("pause");
    return 0;
}
