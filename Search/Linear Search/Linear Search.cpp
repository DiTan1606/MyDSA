#include <iostream>
using namespace std;

// Bài toán tìm kiếm: Cho mảng a gồm n phần tử, và biến x cho trước.
// Tìm trong mảng a phần tử có giá trị bằng x. Nếu ai  = x thì trả về i
// 
// Linear_search: mảng a chưa có thứ tự
// duyệt tuần tự các phần tử của mảng a, để xác định ai = x trả về i ngược lại trả về -1;

// Linear_search_CT: cải tiến điều kiện dừng của linear_search bằng cách thêm phần tử a[n] = x, 
// khi đó điều kiện dừng của thuật toán là tìm thấy ai = x;
// nếu i < n là tìm thấy trả về i
// nếu i == n là không tìm thấy trả về -1

int n, a[100];
void nhap() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
int Linear_search(int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}
int Linear_search_CT(int x) {
    a[n] = x;
    int i = 0;
    while (a[i] != x) {
        i++;
    }
    if (i < n) {
        return i;
    }
    else {
        return -1;
    }
}

int main()
{
    cin >> n;
    nhap();
    int x;
    cin >> x;
    cout << Linear_search_CT(x);
}
