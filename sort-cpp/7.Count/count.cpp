#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e2;

void count_sort(int arr[], int n) {
    int max_num = arr[0];
    for (int i = 1; i < n; i++) if (max_num < arr[i]) max_num = arr[i];
    int* tmp = new int[max_num + 1]{ 0 };
    int* result = new int[n] {0};
    for (int i = 0; i < n; i++) tmp[arr[i]]++;
    for (int i = 1; i < max_num + 1; i++) tmp[i] += tmp[i - 1];
    // 这里倒序是为了保证稳定性
    for (int i = n - 1; i > -1; i--) result[--tmp[arr[i]]] = arr[i];
    // void *memcpy(void *destin, void *source, unsigned n);
    // destin-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
    // source-- 指向要复制的数据源，类型强制转换为 void* 指针。
    // n-- 要被复制的字节数。
    memcpy(arr, result, sizeof(int) * n);

    delete[] tmp, result;
    tmp = nullptr, result = nullptr;
}

int main() {
	int n, q[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];
	count_sort(q, n);
	for (int i = 0; i < n; i++) cout << q[i] << " ";

	system("pause");
	return 0;
}