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
    // ���ﵹ����Ϊ�˱�֤�ȶ���
    for (int i = n - 1; i > -1; i--) result[--tmp[arr[i]]] = arr[i];
    // void *memcpy(void *destin, void *source, unsigned n);
    // destin-- ָ�����ڴ洢�������ݵ�Ŀ�����飬����ǿ��ת��Ϊ void* ָ�롣
    // source-- ָ��Ҫ���Ƶ�����Դ������ǿ��ת��Ϊ void* ָ�롣
    // n-- Ҫ�����Ƶ��ֽ�����
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