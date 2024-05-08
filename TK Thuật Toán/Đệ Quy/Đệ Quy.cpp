#include <iostream>
using namespace std;
/*
Đệ quy - bộ nhớ stack
- điểm dừng (bài toán con nhỏ nhất); không có điểm dừng thì sẽ bị tràn bộ nhớ stack 
- công thức truy hồi 
*/ 

// bài toán tổng các số từ 1 -> n
int tong(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + tong(n - 1);
	}
}

// bài toàn tính giai thừa 
int giaithua(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * giaithua(n - 1);
	}
}

// tinh so fibonaci thu n, n qua lon thi k nen dung dequy
long long fibo(int n) {
	if (n <= 2) {
		return 1;
	}
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}

// tinh to hop chap k cua n
int nCk(int n, int k) {
	if (k == 0 || n == k) {
		return 1;
	}
	else {
		return nCk(n - 1, k - 1) + nCk(n - 1, k);
	}
}

// tim ucln 
int UCLN(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return UCLN(b, a % b);
	}
}

// tính binary pow
int b_pow(int a, int b) {
	if (b == 0) {
		return 1;
	} 
	int x = b_pow(a, b / 2);
	if (b%2 == 1) {
		return a * x * x;
	}
	else {
		return x * x;
	}
}
 
// dem so chu so cua mot so
int count(int n) {
	if (n < 10) {
		return 1;
	} 
	else {
		return 1 + count(n / 10);
	}
}

// kiem tra mang doi xung
bool kt_mangdoixung(int a[], int l, int r) {
	if (l >= r) {
		return true;
	}
	if (a[l] != a[r]) {
		return false;
	}
	else {
		return kt_mangdoixung(a, l + 1, r - 1);
	}
}

int main()
{
	cout << tong(5) << endl;
	cout << giaithua(5) << endl;
	cout << fibo(5) << endl;
	cout << nCk(10,2) << endl;
	cout << UCLN(10, 45) << endl;
	cout << b_pow(2, 10) << endl;
	cout << count(12345) << endl;
	int a[] = { 1,2,3,2,1 };
	if (kt_mangdoixung(a, 0, 4)) {
		cout << "doi xung" << endl;
	}
}
