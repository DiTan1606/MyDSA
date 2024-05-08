#include <iostream>
using namespace std;
/*
Thuật toán quay lui dùng để giải bài toán liệt kê các cấu hình.
Mỗi cấu hình được xây dựng bằng cách xây dựng từng phần tử, mỗi phần tử được chọn bằng cách thử tất cả các khả năng
1- Xét tất cả các giá trị x1 có thể nhận, thử cho x1 nhận tất cả các giá trị đó. Với mỗi giá trị thử gán cho x1 ta sẽ:
2- Xét tất cả các giá trị x2 có thể nhận, lại thử cho x2 nhận tất cả các giá trị đó. Với mỗi giá trị thử gán cho x2 lại xét tiếp các khả năng chọn x3 ... cứ tiếp tục như vậy đến bước:
...
n- Xét tất cả các giá trị xn có thể nhận, thử cho xn nhận tất cả giá trị đó, thông báo cấu hình tìm được (x1,x2,x3,...,xn)

Mã giả: là một thuật toán đệ quy
giả sử xây dựng cấu hình có dạng (x1,x2,...,xn)
một cái x sẽ có M khả năng
Try(int i) 
{
    for (j = khả năng 1; j <= khả năng M; j++) 
    {
        if (chấp nhận khả năng j) 
        {
            X[i] = khả năng j
            if (i == n) 
            {
                thông báo cấu hình tìm được
            }
            else 
            {
                Try(i+1)
            }
        }
    }
}
*/

//=========================================================

// bài toán xây dựng xâu nhị phân có độ dài n
// i: 1 -> n
// mỗi bit Xi co 2 kha năng 1 hoặc 0
// j: 0 -> 1
// bin = X1X2X3...Xn
//int bin[100], n;
//
//void inKQ_bin() {
//    for (int i = 1; i <= n; i++) {
//        cout << bin[i];
//    }
//    cout << endl;
//}
//
//void Try(int i) {
//    for (int j = 0; j <= 1; j++) {
//        bin[i] = j;
//        if (i == n) {
//            inKQ_bin();
//        }
//        else {
//            Try(i + 1);
//        }
//    }
//}

//=========================================================

// bài toán tổ hợp chập k của n
// i = 1 -> k
// moi so gioi han trong khoang
// x[i-1]+1 -> n-k+i

//int nCk[100],n, k;
//void inKQ_nCk() {
//    for (int i = 1; i <= k; i++) {
//        cout << nCk[i];
//    }
//    cout << endl;
//}
//void Try(int i) {
//    for (int j = nCk[i-1] + 1; j <= n - k + i; j++) {
//        nCk[i] = j;
//        if (i == k) {
//            inKQ_nCk();
//        }
//        else {
//            Try(i + 1);
//        }
//    }
//}

//=========================================================

// bai toan tim n hoan vi
// i = 1 -> n
// 
//

//int HV[100], used[100], n;
//void inKQ_hoanvi() {
//    for (int i = 1; i <= n; i++) {
//        cout << HV[i];
//    }
//    cout << endl;
//}
//void Try(int i) {
//    for (int j = 1; j <= n; j++) {
//        if (used[j] == 0) {
//            HV[i] = j;
//            used[j] = 1;
//            if (i == n) {
//                inKQ_hoanvi();
//            }
//            else {
//                Try(i + 1);
//            }
//            used[j] = 0;
//        }
//    }
//}

//=========================================================

// Bài toán cổ điển của thuật toán quay lui: N quân hậu
// Tìm cách sắp xếp N quân hậu vào N hàng trên bàn cờ vua cở NxN sao cho không có 2 quân hậu ăn nhau
// Gọi X = (X1,X2,...,XN) là một nghiệm của bài toán, khi đó nếu Xi = j thì có nghĩa ta xếp quân hậu ở hàng i cột j
// 
//

int Queen[100],  cot[100], d1[100], d2[100], n , cnt;
int a[100][100];

void inKQ_NQueen() {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        a[i][Queen[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1) {
            Queen[i] = j;
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            if (i == n) {
                inKQ_NQueen();
                cnt++;
            }
            else {
                Try(i+1);
            }
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}

int main()
{   
    cin >> n;
    for (int i = 1; i <= 99; i++) {
        cot[i] = d1[i] = d2[i] = 1;
    }
    Try(1);
    cout << cnt;
}
