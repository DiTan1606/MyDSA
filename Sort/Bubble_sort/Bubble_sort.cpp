#include <iostream>
using namespace std;

// Bubble_sort: Ý tưởng thuật toán cũng giống như việc thầy giáo xếp hàng trong giờ thể dục.
// Để sắp xếp từ thấp đến cao: thầy so sánh 2 bạn đứng cạnh nhau, nếu bạn bên phải thấp hơn bạn bên trái thì đổi chỗ 2 bạn cho nhau 
// Để sắp xếp từ cao đến thấp: thầy so sánh 2 bạn đứng cạnh nhau, nếu bạn bên phải cao hơn bạn bên trái thì đổi chỗ 2 bạn cho nhau
// Thuật toán thực hiện sắp xếp dãy số bằng cách lặp lại công việc đổi chỗ 2 số liên tiếp nhau nếu chúng đứng sai thứ tự cho đến khi dãy số được sắp xếp
// Như vậy mỗi lần lặp thuật toán sẽ đưa phần tử lớn nhất ra cuối dãy hoặc nhỏ nhất về đầu dãy;

int a[100], n;
void nhap() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Bubble_sort_TD() {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                xuat();
            }
        }
    }
}
void Bubble_sort_GD() {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
                xuat();
            }
        }
    }
}

int main()
{
    cin >> n;
    nhap();
    Bubble_sort_TD();
    xuat();
    Bubble_sort_GD();
    xuat();
}