#include <iostream>
using namespace std;

// Selection_sort: thuật toán thực hiện bằng cách đi tìm phần tử nhỏ nhất/lớn nhất trong mảng chưa sắp xếp.
// Sau đó hoán đổi vị trí phần tử đó cho phần tử ở đầu đoạn chưa sắp xếp.
// nhỏ nhất thì là sắp xếp tăng dần
// lớn nhất thì là sắp xếp giảm dần
// O(n^2)

int n, a[100];
void nhap() {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void xuat() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}
void Selection_sort_TD() {
	for (int i = 0; i < n-1; i++) {
		int min_i = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min_i]) {
				min_i = j;
			}
		}
		swap(a[i], a[min_i]);
		//xuat();
	}
}
void Selection_sort_GD() {
	for (int i = 0; i < n - 1; i++) {
		int max_i = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[max_i]) {
				max_i = j;
			}
		}
		swap(a[i], a[max_i]);
		//xuat();
	}
}

int main()
{
	cin >> n;
	nhap();

	Selection_sort_TD();
	xuat();
	
	Selection_sort_GD();
	xuat();
}
