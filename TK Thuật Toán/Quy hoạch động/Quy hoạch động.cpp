#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

// Quy hoạch động: là phương pháp giảm thời gian chạy của các thuật toán
// sử dụng khi 
// + có các bài toán con gối nhau : sử dụng khi các bài toán con được gọi đi gọi lại, QHD sẽ giúp lưu kq của bài toán con khi được gọi sẽ k phải tính lại. ví dụ bài tính fibo
// + có cấu trúc con tối ưu: cho phép chúng ta giải bài toán lớn dựa vào các bài toán con đã giải được. 

// ================================================================================

// fibo bang de quy
//int fibo(int x) {
//    if (x <= 2) {
//        return 1;
//    }
//    else {
//        return fibo(x - 2) + fibo(x - 1);
//    }
//}

// fibo bằng quy hoạch động
//long long f[1000];
//long long fibo(int x) {
//    f[1] = f[2] = 1;
//    for (int i = 3; i <= 92; i++) {
//        f[i] = f[i - 2] + f[i - 1];
//    }
//    return f[x];
//}

// fibo bằng đệ quy có nhớ 
//long long f[100];
//
//long long fibo(int x) {
//	if (x <= 2) return 1;
//	f[x] = fibo(x-2) + fibo(x-1);
//	if (f[x] != -1) return f[x];
//	return f[x];
//}

// ================================================================================
// LIS: longest increase sub 
// tìm ra độ dài của dãy con tăng dài nhất
// O(n^2)
// L[i] độ dài của dãy con tăng dài nhất kết thúc ở chỉ số j
// l[i] = max(L[i],l[j]+1) : a[i] > a[j]

//int LIS() {
//	int n;
//	cin >> n;
//	vector <int> a;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		a.push_back(x);
//	}
//	vector <int> L(n, 1);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i; j++) {
//			if (a[i] > a[j]) {
//				L[i] = max(L[i], L[j] + 1);
//			}
//		}
//	}
//	return *max_element(L.begin(), L.end());
//}

// ================================================================================
// Bài toán cái túi của tên trộm :
// Một tên trộm có 1 cái túi có thể mang các đồ vật với trọng lượng tối đa là W, hiện tên trộm muốn lựa chọn các đồ vật trong N đồ vật để trộm.
// Mỗi đồ vật có trọng lượng là w[i] và giá trị là v[i].
// Hãy xác định tổng giá trị lớn nhất của các đồ vật mà tên trộm này lựa chọn sao cho trọng lượng của chúng không vượt quá W
// tao dp[][] voi dp[i][j] là giá trị lớn nhất của cái túi khi lựa chọn các đồ vật 1,2,3,..,i có khối lượng i 

void MaxValueTrongTuiTenTrom() {
	int n,W; cin >> n >> W;
	int w[100], v[100];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int dp[100][100];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << dp[n][W];
}

int main()
{
	//memset(f, -1, sizeof f);
	MaxValueTrongTuiTenTrom();
}  

