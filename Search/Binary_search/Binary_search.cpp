#include <iostream>
using namespace std;

// Binary_search: mảng a đã có thứ tự
// Áp dụng kĩ thuật chia để trị
// chọn am ở giữa a và tận dụng kết quả so sánh am với x, chia a thành 2 phần: trước am, sau am
// Chỉ số bắt đầu, kết thúc là l, r;
// nếu x = am trả về m;
// nếu x < am thì tìm x trong đoạn [l,m+1]
// nếu x > am thì tìm x trong đoạn [m+1,r]
// 

int a[100], n;
void nhap() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
int Binary_search(int x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (x == a[m]) {
            return m;
        }
        else if (x < a[m]) {
            r = m - 1;
        }
        else if (x > a[m]) {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    nhap();
    int x;
    cin >> x;
    cout << Binary_search(x);
}
