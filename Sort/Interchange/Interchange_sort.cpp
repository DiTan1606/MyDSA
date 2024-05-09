#include <iostream>
using namespace std;

// Interchange_sort: Xuất phát từ đầu dãy, tìm tất cả các nghịch thế chứa phần tử này
// triệt tiêu chúng bằng cách đổi chỗ 2 phần tử trong cặp nghịch thế. Lặp lại với phần tử kế tiếp trong dãy
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
void Interchange_sort_TD() {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void Interchange_sort_GD() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
int main()
{
	cin >> n;
	nhap();
	Interchange_sort_TD();
	xuat();
	Interchange_sort_GD();
	xuat();
}
