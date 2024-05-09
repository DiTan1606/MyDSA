#include <iostream>
using namespace std;

// Insertion_sort: là một thuật toán sắp xếp bắt chước cách sắp xếp quân bài của những người chơi bài.
// Thuật toán thực hiện sắp xếp dãy số theo cách duyệt từng phần tử và chèn từng phần tử đó vào đúng vị trí trong mảng con đã sắp xếp (dãy số từ đầu đến phần tử phía trước nó)  
// sao cho dãy số trong mảng đã sắp xếp vẫn đảm báo tính chất giảm dần / tăng dần
// O(n^2)

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
void Insertion_sort_TD() {
    for (int i = 1; i < n; i++) {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && a[pos] > x) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
        //xuat();
    }
}
void Insertion_sort_GD() {
    for (int i = 1; i < n; i++) {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && a[pos] < x) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
        //xuat();
    }
}
int main()
{
    cin >> n;
    nhap();
    Insertion_sort_TD();
    xuat();
    Insertion_sort_GD();
    xuat();
}