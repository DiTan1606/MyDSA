#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sort(vt pt dau, vt sau pt cuoi, tieu chi sx)
// tieu chi sx mac dinh = tang dan
// greater<int>(): giam dan
// sort O(nlogn)
// stable_sort O(nlog^2(n))
// co the tu cai dat cac tieu chi sap xep
// stable_sort

int tong(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool cmp(int a, int b) {
    return (tong(a) < tong(b));
}

int main()
{
    vector <int> v;
    for (int i = 0; i < 7; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    stable_sort(v.begin(), v.end(), cmp);
    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}
