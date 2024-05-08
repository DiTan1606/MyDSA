#include <iostream>
#include <algorithm>
using namespace std; 

 
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
long long f[100];

long long fibo(int x) {
	if (x <= 2) return 1;
	f[x] = fibo(x-2) + fibo(x-1);
	if (f[x] != -1) return f[x];
	return f[x];
}

int main()
{
	memset(f, -1, sizeof f);
	cout << fibo(5);
}

