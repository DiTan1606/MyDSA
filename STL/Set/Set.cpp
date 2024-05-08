#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
// set: chi luu cac phan tu co gia tri rieng biet, sx tang dan
// set<int> s;
// insert(value)
// size() => int
// khong the duyet bang chi so vi k dung [] duoc
// clear() xoa het tat ca cac phan tu
// empty() => bool kiem tra set rong
// O(logn)
// erase(value) xoa phan tu value trong set
// find(value) => tim kiem phan tu value tra iterator tro den phan tu do nguoc lai tra ve end() 
// count(value) => dem so lan xuat hien cua phan tu value tra ve bool

// multiset: co the luu cac phan tu co cung gia tri, van sx tang dan
// erase(value) => xoa het tat ca cac phan tu value 
// find(value) => tra ve iterator cua phan tu value dau tien
// lower_bound(value) => tim kiem tra ve interator tro toi phan tu dau tien >= value
// upper_bound(value) => tim kiem tra ve interator tro toi phan tu dau tien > value

// unordered_set: chi luu cac phan tu co gia tri rieng biet, khong co thu tu
// best O(1)
// worst O(n)
int main()
{
    unordered_set<int> ms;
    ms.insert(2);
    ms.insert(4);
    ms.insert(8);
    ms.insert(1);
    ms.insert(6);
    ms.insert(5);

    for (int x : ms) {
        cout << x << " ";
    }
    cout << endl;
}