#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// Tham lam: là một phương án giải quyết vấn đề mà trong đó ta tìm ra một cách để tạo ra kết quả tốt nhất. 
// Tuy nhiên đôi lúc kết quả này lại sai nếu khong cân nhắc cụ thể

//==========================================================================================

// Bài toán mua sách
// Trong nhà sách đang bán một bộ sách gồm n cuốn sách có giá là a[i]. Nhà sách đang có chương trình ưu đãi là mua 3 cuốn sẽ miễn phí cuốn có giá thấp nhất.
// Tìm chi phí thấp nhất để mua n cuốn sách

//int a[100], n;
//void nhap() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//}
//void xuat() {
//    for (int i = 1; i <= n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//}
//void sort_GD() {
//    for (int i = 1; i < n; i++) {
//        for (int j = i + 1; j <= n; j++) {
//            if (a[i] < a[j]) {
//                swap(a[i], a[j]);
//            }
//        }
//    }
//}
//void MuaSach() {
//    int ans = 0;
//    nhap();
//    sort_GD();
//    xuat();
//    for (int i = 1; i <= n; i++) {
//        if (i % 3 == 0) {
//            continue;
//        }
//        ans += a[i];
//    }
//    cout << ans;
//}

//==========================================================================================

// Bài toán đổi tiền
// tại ngân hàng có các mệnh giá 1, 2, 5, 10, 20, 50, 100, 200, 500 (đơn vị nghìn đồng)
// một người cần đổi số tiền có giá trị N. Hãy xác định số tờ tiền ít nhất sau khi đổi 

//int a[] = { 500,200,100,50,20,10,5,2,1 }, N;
//void DoiTien() {
//	int soToTien = 0;
//	cin >> N;
//	cout << N << " = ";
//	for (int i = 0; i < 9; i++) {
//		if (N / a[i] > 0) {
//			soToTien += N / a[i];
//			cout << N / a[i] << "x" << a[i];
//			N %= a[i];
//			if (N != 0) {
//				cout << " + ";
//			}
//		}
//		
//	}
//	cout << endl;
//	cout << soToTien;
//}

int main()
{
	
}
