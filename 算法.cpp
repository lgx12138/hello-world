#include <iostream>
using namespace std;
#define N 100
int arr[N], temp[N], brr[N];
void quick_sort(int*, int, int);
void merge_sort(int*, int, int);
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	 quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << endl;
	
	return 0;
}
//二路归并
void merge_sort(int* arr, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2, i = l, j = mid + 1;  
	merge_sort(arr, l, mid), merge_sort(arr, mid+1, r); //将arr分成两组， l ~ mid 为一组 ，mid +1 ~ r是一组，将两组归并
	int k = 0;
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= r) temp[k++] = arr[j++];
	for (int i = l, k = 0; i <= r; i++,k++) {
		arr[i] = temp[k];
	}
}

void quick_sort(int* arr, int l, int r) {
	if (l >= r) return;
	int x = arr[(l + r) / 2], i = l - 1, j = r + 1;
	if (i < j) {
		do { i++; } while (arr[i] < x);
		do { j--; } while (arr[j] > x);
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
	quick_sort(arr, l, j), quick_sort(arr, j + 1, r);
}
