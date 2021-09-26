#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e2;

int max_len(int arr[], int n) {
    int max_num = arr[0], num = 0;
    for (int i = 1; i < n; i++) if (max_num < arr[i]) max_num = arr[i];
    while (max_num >= 1) {
        num++;
        max_num /= 10;
    }
    return num;
}

void lsd_sort(int arr[], int n) {
    int k = max_len(arr, n), gap = 1, index = 0;
    while (k--) {
        int* result = new int[n] {0};
        int count[10]{ 0 };
        for (int i = 0; i < n; i++) {
            index = (arr[i] / gap) % 10;
            count[index]++;
        }
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = n - 1; i > -1; i--) {
            index = (arr[i] / gap) % 10;
            result[--count[index]] = arr[i];
        }
        for (int i = 0; i < n; i++) arr[i] = result[i];
        gap *= 10;

        delete[] result;
        result = nullptr;
    }
}

void msd_sort(int arr[], int l, int r, int d) {
    int count[10]{ 0 }, res[11]{ 0 }, index = 0;
    int* tmp = new int[r - l + 1];
    for (int i = l; i < r + 1; i++) {
        index = int(arr[i] / pow(10, d - 1)) % 10;
        count[index]++;
    }
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    // 先将 count 数组的值都赋值给 res 数组，因为后续 count 数组各值都置零了
    // 之所以 res 的容量比 count 多1，是为了后续 p1 和 p2 边界不遗漏 count[0]
    for (int i = 0; i < 10; i++) res[i + 1] = count[i];
    for (int i = r; i > l - 1; i--) {
        index = int(arr[i] / pow(10, d - 1)) % 10;
        tmp[--count[index]] = arr[i];
    }
    // 此时，res[i] 为第 i 个桶的左边界
    for (int i = l, j = 0; i <= r; i++, j++) arr[i] = tmp[j];
    delete[] tmp;
    tmp = nullptr;
    for (int i = 0; i < 10; i++) {
        int p1 = l + res[i], p2 = l + res[i + 1] - 1;
        if (p1 < p2 && d > 1) msd_sort(arr, p1, p2, d - 1);
    }
}

int main() {
    int n, q[N] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    //lsd_sort(q, n);
    int d = max_len(q, n);
    msd_sort(q, 0, n - 1, d);
    for (int i = 0; i < n; i++) cout << q[i] << " ";

    system("pause");
    return 0;
}