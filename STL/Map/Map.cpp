#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

/*
Map: giup luu cac cap gia tri(key - value)
- co the cung kieu hoac khac kieu
- chi luu cac key rieng biet
- tang dan theo key
1. khai bao
    map<kdl1, kdl2> ten_map;
2. insert();
    mp.insert(pair<int, int>(5, 9));
    mp.insert({ 10,7 });
3. clear()
4. empty() => rong tra ve true
5. erase(key) : vi key la duy nhat
    erase(iterator)
6. find(key) / count(key)
=> O(nlogn)


multiMap: giup luu cac cap gia tri (key-value)
- co the cung kieu hoac khac kieu
- co the luu cac key rieng biet
- tang dan theo key
- erase(key) => xoa het pt co key
- find(key) => tra ve pt dau tien co key
- upper_bound() => tra ve iterator tro toi phan tu dau tien > key
- lower_bound(key) => tra ve iterator tro toi phan tu dau tien >= key
=> O(nlogn)


unorderedMap: giup luu cac cap gia tri (key - value)
- co the cung kieu hoac khac kieu
- luu cac key rieng biet
- sap xep khong co thu tu
*/ 

int main()
{
    unordered_map<int, string> mp;
    mp.insert({ 3, "Nguyen Van A" });
    mp.insert({ 2, "Tran Van B" });
    mp.insert({ 3, "Pham C" });
    mp.insert({ 1, "Nguyen Thi D"});
    for (auto x : mp) {
        cout << x.first << ": " << x.second << endl;     
    }
    cout << mp.count(3);
    return 0;
}
