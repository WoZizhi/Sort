#include <iostream>

using namespace std;

const int N = 1e2;
void heap_adjust(int arr[], int root, int n);

void heap_build(int arr[], int n) {
    for (int i = n - 2 >> 1; i > -1; i--) heap_adjust(arr, i, n);
}

void heap_adjust(int arr[], int root, int n) {
    int largest = root, leftnode = 2 * root + 1, rightnode = 2 * root + 2;
    if (leftnode < n && arr[leftnode] > arr[largest]) largest = leftnode;
    if (rightnode < n && arr[rightnode] > arr[largest]) largest = rightnode;
    if (largest != root) {
        int tmp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = tmp;
        heap_adjust(arr, largest, n);
    }
}

void heap_sort(int arr[], int n) {
    if (n < 2) return;
    heap_build(arr, n);
    while (--n) {
        int tmp = arr[0];
        arr[0] = arr[n];
        arr[n] = tmp;
        heap_adjust(arr, 0, n);
    }
}

void bucket_sort(int arr[], int n) {
    if (n < 2) return;
    int max_num = arr[0], min_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (max_num < arr[i]) max_num = arr[i];
        if (min_num > arr[i]) min_num = arr[i];
    }
    int k = max_num / 10 - min_num / 10 + 1, index = 0, cur = 0;
    int** bucket = new int* [k];
    int* count = new int[k] {0};
    for (int i = 0; i < k; i++) bucket[i] = new int[n] {0};
    for (int i = 0; i < n; i++) {
        index = arr[i] / 10 - min_num / 10;
        bucket[index][count[index]++] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        heap_sort(bucket[i], count[i]);
        for (int j = 0; j < count[i]; j++) arr[cur++] = bucket[i][j];
    }

    for (int i = 0; i < k; i++) delete[] bucket[i];
    delete[] bucket;
    bucket = nullptr;
    delete[] count;
    count = nullptr;
}

int main() {
    int n, q[N] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    bucket_sort(q, n);
    for (int i = 0; i < n; i++) cout << q[i] << " ";

    system("pause");
    return 0;
}